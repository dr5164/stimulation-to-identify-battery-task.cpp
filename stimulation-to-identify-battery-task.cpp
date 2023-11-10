#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class Task {
private:
  string name;
  int batteryConsumption;

public:
  Task(const string& name, int batteryConsumption) {
    this->name = name;
    this->batteryConsumption = batteryConsumption;
  }

  void run() {
    cout << "Task \"" << name << "\" started." << endl;

    for (int i = 0; i <= 100; i += 10) {
      this_thread::sleep_for(chrono::milliseconds(100));
      cout << "Task \"" << name << "\" progress: " << i << "%" << endl;
    }

    cout << "Task \"" << name << "\" completed in 1 second." << endl;
  }

  int getBatteryConsumption() const {
    return batteryConsumption;
  }

  string getName() const {
    return name;
  }

  static int getTotalBatteryConsumptionPercentage(const vector<Task>& tasks) {
    int totalBatteryConsumption = 0;
    for (const auto& task : tasks) {
      totalBatteryConsumption += task.getBatteryConsumption();
    }
    return totalBatteryConsumption;
  }
};

int main() {
  // Create tasks
  vector<Task> tasks;
  tasks.push_back(Task("Task 1", 10));
  tasks.push_back(Task("Task 2", 15));
  tasks.push_back(Task("Task 3", 5));

  cout << "Tasks running..." << endl;

  // Run tasks
  for (auto& task : tasks) {
    task.run();
    cout << "Logging data - Task: " << task.getName() << ", Duration: 1 second." << endl;
  }

  // Calculate total battery consumption percentage by tasks
  int totalBatteryConsumption = Task::getTotalBatteryConsumptionPercentage(tasks);
  cout << "Total battery consumption percentage by tasks: " << totalBatteryConsumption << "%" << endl;

  return 0;
}
