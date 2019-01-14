#pragma once

#include <initializer_list>
#include <stdexcept>
#include "../TypeRedefinitions.h"
#include "../StandardOperations.h"
#include "Core.h"
#include "Util.h"

typedef std::vector<int> m_color_chunk;

const m_color_chunk red   = {255, 0,   0};
const m_color_chunk green = {0,   255, 0};
const m_color_chunk blue  = {0,   0,   255};
const m_color_chunk white = {255, 255, 255};
const m_color_chunk black = {0,   0,   0};

// this function doesnt actually plot lines, it sets grid line data in the PlotWindow 
// object so it can plot later without having to perform any calculations
void PlotGridLines(PlotWindow& pwin, real_set_t& x_axis, real_set_t& y_axis, real_t spacing, const m_color_chunk& color) {
    pwin.reset_grid_lines();
    pwin.set_uses_grid_lines(true);

    real_t min_x = Min(x_axis);
    real_t max_x = Max(x_axis);
    real_t min_y = Min(y_axis);
    real_t max_y = Max(y_axis);

    for(real_t y = 0; y <= max_y; y += spacing)
        pwin.add_h_grid_line(map_real(y, min_y, max_y, 0.0, 1.0f));

    for(real_t y = 0; y >= min_y; y -= spacing)
        pwin.add_h_grid_line(map_real(y, min_y, max_y, 0.0, 1.0f));
        
    for(real_t x = 0; x <= max_x; x += spacing)
        pwin.add_v_grid_line(map_real(x, min_x, max_x, 0.0f, 1.0f));

    for(real_t x = 0; x >= min_x; x -= spacing)
        pwin.add_v_grid_line(map_real(x, min_x, max_x, 0.0f, 1.0f));

}

// fit all information present in the graph
void PlotPlain(PlotWindow& pwin, real_set_t& x_axis, real_set_t& y_axis, const m_color_chunk& color) {
    if(x_axis.size() != y_axis.size())
        throw std::runtime_error("plot_plain -> input vectors must be the same size");

    real_t min_x = Min(x_axis);
    real_t max_x = Max(x_axis);
    real_t min_y = Min(y_axis);
    real_t max_y = Max(y_axis);

    // plot functions always map input data to a 1x1 fp 
    // square. the PlotWindow re-maps that to appropiate 
    // screen coordinates with some buffering on the edges

    pwin.clear();
    pwin.set_color(color);

    int sz = x_axis.size();
    for(int index = 0; index < sz; index++) {
        real_t x_input = x_axis[index];
        real_t y_input = y_axis[index];

        real_t mapped_x = map_real(x_input, min_x, max_x, 0.0f, 1.0f);
        real_t mapped_y = map_real(y_input, min_y, max_y, 0.0f, 1.0f);

        pwin.plotAt(mapped_y, mapped_x, color);
    }

    pwin.update_screen();

}


