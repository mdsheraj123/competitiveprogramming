#include <fstream>

using namespace std;

int main() {
    ifstream expectedOutput("expectedOutput.txt");
    ifstream output("../output.txt");

    int result = 0;

    while (true) {
        string line1, line2;
        getline(expectedOutput, line1);
        getline(output, line2);

        if (line1 != line2) {
            result = 1;
            break;
        }

        if (!output && !expectedOutput) {
            break;
        } else if (!output || !expectedOutput) {
            result = 1;
            break;
        }
    }

    output.close();
    expectedOutput.close();

    return result;
}