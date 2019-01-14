#pragma once

#include <vector>
#include <utility>
#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>

class PlotWindow {
private:
    int rows = 0, columns = 0;
    SDL_Surface* surface = NULL;

    std::vector<std::pair<int, int>> pt_vector;
    std::vector<int> current_color;

    // grid information
    bool using_grid = false;
    std::vector<int> grid_color;
    std::vector<int> v_lines;
    std::vector<int> h_lines;

    // start up the SDL subsystems
    void initialize_screen(void);

public:

    // default constructor creates a 640x480 window
    PlotWindow(void);

    // otherwise, specify a size that you want
    PlotWindow(int rows, int columns);

    // destroy SDL instance and release all 
    // memory associated with it
    ~PlotWindow(void);

    void set_color(const std::vector<int>& color) {
        this->current_color = color;
    }

    // return data about the video buffer
    auto format(void) -> SDL_PixelFormat* { return this->surface->format; }
    auto screen(void) -> SDL_Surface* { return this->surface; }

    // equivalent to blanking the screen
    void clear(void) { SDL_FillRect(this->surface, NULL, 0x00000000); }

    // these are only really needed by the plotting utilities
    int getRows(void) { return this->rows; }
    int getColumns(void) { return this->columns; }

    // PlotWindow takes care of mapping floating point values 
    // to integer screen coordinates
    void plotAt(float y, float x, const std::vector<int>& color);

    // flip the current framebuffer
    void update_screen(void) { SDL_Flip(this->surface); }

    // wait until the user presses a key
    void wait_for_keypress(void);

    // helps when drawing connected lines 
    // on the screen
    void save_temps(void);

    // draw the line given by the most recent plot routines
    void draw_connected_lines(void);

    // methods associated with drawing grid lines on a plot
    void set_grid_color(const std::vector<int>& color) { this->grid_color = color; }
    void reset_grid_lines(void) { this->v_lines.clear(); this->h_lines.clear(); }
    void add_v_grid_line(real_t v) { this->v_lines.push_back(map_real(v, -0.05, 1.05, 0, this->columns)); }
    void add_h_grid_line(real_t h) { this->h_lines.push_back(map_real(h, -0.05, 1.05, this->rows, 0)); }
    void draw_grid(void);
    void set_uses_grid_lines(bool b) { this->using_grid = b; }
};

// by this point, the grid has already
void PlotWindow::draw_grid(void) {
    auto g_clr = SDL_MapRGB(this->format(), grid_color[0], grid_color[1], grid_color[2]);
    
    for(int x : this->v_lines) {
        SDL_Rect r;
        r.x = x;
        r.y = 0;
        r.h = this->rows;
        r.w = 1;
        SDL_FillRect(this->surface, &r, g_clr);
    }

    for(int y : this->h_lines) {
        SDL_Rect r;
        r.x = 0;
        r.y = y;
        r.h = 1;
        r.w = this->columns;
        SDL_FillRect(this->surface, &r, g_clr);
    }

}

void PlotWindow::draw_connected_lines(void) {
    std::pair<int, int> last_p = this->pt_vector[0];
    for(std::pair<int, int> current_p : this->pt_vector) {
        // draw a line between the two points we have. the 
        // first one will be drawn between two of the same points
    
        lineRGBA(this->surface, last_p.first, last_p.second, current_p.first, current_p.second, 
        current_color[0], current_color[1], current_color[2], 255);

        // prep for next iteration
        last_p = current_p;
    }
}

void PlotWindow::save_temps(void) {
    this->pt_vector.clear();
}

void PlotWindow::wait_for_keypress(void) {

    while(true) {

        this->clear();

        if(this->using_grid) {
            this->draw_grid();
        }

        this->draw_connected_lines();
        this->update_screen();

        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                case SDL_KEYDOWN:
                    return;
                default:
                    break;
            }

            usleep(50000);
        }
    }
}

void PlotWindow::plotAt(float m_y, float m_x, const std::vector<int>& color) {
    int x = map_real(m_x, -0.05, 1.05, 0, this->columns);
    int y = map_real(m_y, -0.05, 1.05, this->rows, 0);

    // makes plotting much easier for next time
    this->pt_vector.push_back({x, y});

    SDL_Rect r;
    r.h = 1;
    r.w = 1;
    r.x = x;
    r.y = y;

    SDL_FillRect(this->surface, &r, SDL_MapRGB(this->surface->format, color[0], color[1], color[2]));
}

void PlotWindow::initialize_screen(void) {
    SDL_Init(SDL_INIT_EVERYTHING);
    this->surface = SDL_SetVideoMode(this->columns, this->rows, 32, SDL_SWSURFACE);
}

PlotWindow::PlotWindow(void) {
    this->rows = 480;
    this->columns = 640;
    this->initialize_screen();
}

PlotWindow::PlotWindow(int rows, int columns) {
    this->rows = rows;
    this->columns = columns;
    this->initialize_screen();
}

PlotWindow::~PlotWindow(void) {
    SDL_Quit();
}

// ================================================
// a small function simply to keep in 
// line with what has already been created
// ================================================
void WaitForKeypress(PlotWindow& pwin) {
    pwin.wait_for_keypress();
}
