#include <iostream>
#include <ToolBox.h>

using namespace std;

int main(int argc, char* argv[]) {
/*
    WaitForKeypress();

    real_set_t rs{1, 2, 3, 4, 5, 6};

    cout << "Data set: " << rs << endl;
    cout << "Sample sd: " << StandardDeviation(rs, SD::sample) << endl;
    cout << "Population sd: " << StandardDeviation(rs, SD::population) << endl;

    auto ci = ConfidenceInterval(rs, zValue::_90);
    ci.useMeanRange();
    cout << "Confidence Interval (90%): " << ci << endl;
    ci.useMaxMin();
    cout << "Confidence Interval [min, max]: " << ci << endl;

    cout << "Mean (avg): " << Mean(rs) << endl;

    FillRandom(rs);
    cout << "Fill random: " << rs << endl;

    Scale(rs, 10.0); // make each element 10x larger
    cout << "Scale (x10): " << rs << endl;

    IO::LoadVector("testfiles/samplevector.txt", rs);
    cout << "Vector from file: " << rs << endl;

    real_matrix_t rm;
    IO::LoadMatrix("testfiles/samplematrix.txt", rm);
    cout << "Matrix from file: \n" << rm << endl;
    cout << "Matrix access rm[2][2]: " << rm[2][2] << endl;

    //string_matrix_t sm;
    //IO::LoadCSV("testfiles/sample.csv", sm);
    //cout << "CSV file loaded" << endl;

    WaitForKeypress();

    //cout << "Contents:\n" << sm << endl;
    //auto state_code = sm.IndexOf(0, "statecode");
    //for(int i = 1; i < sm.size(); i++)
    //    cout << sm[i][state_code] << ", ";

    WaitForKeypress();
*/
    real_set_t new_set;
    CreateRange(new_set, 100, 0.0, 3.14159265 * 3);
    auto result = Eval(new_set, sin);
    cout << result;

    PlotWindow pwin;
    PlotGridLines(pwin, new_set, result, 1.0, blue);
    PlotPlain(pwin, new_set, result, red);

    WaitForKeypress(pwin);

    return 0;
}
