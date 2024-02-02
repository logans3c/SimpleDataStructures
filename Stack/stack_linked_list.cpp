int main() {
    stack<string> backward_stack;
    stack<string> forward_stack;

    ifstream file("urls.txt");
    if (file.is_open()) {
        string line;
        string instructions;

        while (getline(file, line)) {
            if (!line.empty()) {
                if (line.find(' ') != string::npos || line.find('9') != string::npos) {
                    instructions = line;
                } else {
                    backward_stack.push(line);
                }
            }
        }
        file.close();

        string current_url = backward_stack.pop();
        cout << "The current page is: " << current_url << endl;

        stringstream ss(instructions);
        string instruction;

        while (ss >> instruction) {
            if (instruction == "Forward") {
                if (!forward_stack.isEmpty()) {
                    backward_stack.push(current_url);
                    current_url = forward_stack.pop();
                    printOptions(current_url, backward_stack.isEmpty() ? "" : backward_stack.peek(), forward_stack.isEmpty() ? "" : forward_stack.peek(), "Forward");
                }
            } else if (instruction == "Backward") {
                if (!backward_stack.isEmpty()) {
                    forward_stack.push(current_url);
                    current_url = backward_stack.pop();
                    printOptions(current_url, backward_stack.isEmpty() ? "" : backward_stack.peek(), forward_stack.isEmpty() ? "" : forward_stack.peek(), "Backward");
                }
            } else {
                cout << "Instruction: " << instruction << endl;
            }
        }

        } else {
            cout << "Unable to open file." << endl;
            return 0;
        }

        return 0;
    }