//Sachal Raja Task4

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

void addTask(vector<Task>& tasks, const string& description) {
    tasks.push_back(Task(description));
    cout << "Task added: " << description << endl;
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks in the list." << endl;
    } else {
        cout << "Task List:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << (tasks[i].completed ? "[✔] " : "[ ] ") << tasks[i].description << endl;
        }
    }
}

void markCompleted(vector<Task>& tasks, int index) {
    if (index >= 0 && index < static_cast<int>(tasks.size())) {
        tasks[index].completed = true;
        cout << "Task marked as completed: " << tasks[index].description << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

void removeTask(vector<Task>& tasks, int index) {
    if (index >= 0 && index < static_cast<int>(tasks.size())) {
        cout << "Task removed: " << tasks[index].description << endl;
        tasks.erase(tasks.begin() + index);
    } else {
        cout << "Invalid task index." << endl;
    }
}

void menu()
{
    cout << "\nTodo List Manager" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "0. Reprint Menu"<<endl;
}

int main() {
    vector<Task> tasks;
    
    menu();
    
    while (true) {

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 5) {
            break; // Exit the program
        }

        switch (choice) {
            case 0:
                menu();
            case 1: {
                string taskDescription;
                cout << "Enter task description: ";
                cin.ignore(); // Clear newline character from previous input
                getline(cin, taskDescription);
                addTask(tasks, taskDescription);
                break;
            }
            case 2:
                viewTasks(tasks);
                break;
            case 3: {
                int taskIndex;
                cout << "Enter the task number to mark as completed: ";
                cin >> taskIndex;
                markCompleted(tasks, taskIndex - 1); // Adjust for 0-based index
                break;
            }
            case 4: {
                int taskIndex;
                cout << "Enter the task number to remove: ";
                cin >> taskIndex;
                removeTask(tasks, taskIndex - 1); // Adjust for 0-based index
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
