
# KnapsackProblem

## 📚 Overview

This repository contains solutions for different variations of the **Knapsack Problem**:

- **Unbounded Knapsack**
- **Bounded Knapsack** (To be completed)
- **0-1 Knapsack** (To be completed)

### 🎯 Your task is to:

1. **Complete the code** for the **Bounded Knapsack** and **0-1 Knapsack** problems.
2. **Write tests** to verify your implementations.
3. **Set up CI pipelines** to ensure automated testing.

---

## 🗂 File Structure

- `UnboundedKnapsack.cpp`: **Completed** solution for the Unbounded Knapsack problem.
- `BoundedKnapsack.cpp`: **Template** for the Bounded Knapsack problem (To be completed).
- `ZeroOneKnapsack.cpp`: **Template** for the 0-1 Knapsack problem (To be completed).
- `tests/`: Directory for test files.
- `CMakeLists.txt`: CMake build configuration for the project.
- `install_requirements.sh`: Shell script to install the required dependencies.

---

## 🚀 Getting Started

### 1️⃣ Create Your Repository

Each student must create a **new repository** for this project. You can do this by:

1. Download the provided ZIP file containing the project.
2. Extract it to a local directory.
3. Create a new Git repository for your project:
   ```bash
   git init
   ```
4. Add the files to your new repository:
   ```bash
   git add .
   git commit -m "Initial commit"
   ```
5. Push it to your remote repository (e.g., GitHub).

### 2️⃣ Install Dependencies

Once your repository is set up, navigate to your project directory and run the `install_requirements.sh` script to install all required dependencies.

```bash
chmod +x install_requirements.sh
./install_requirements.sh
```

This will install the necessary packages, including **Google Test** for testing.

### 3️⃣ Complete the Code

- Fill in the missing code in `BoundedKnapsack.cpp` and `ZeroOneKnapsack.cpp`.

### 4️⃣ Write Tests

- Add test cases in the `tests/` directory to ensure correctness.

### 5️⃣ Set up CI Pipelines

- Set up **GitHub Actions** or **Travis CI** to run tests automatically.

---

## 🧪 Running Tests

To build the project and run the tests locally:

1. **Create a build directory** (if you haven't already):
   ```bash
   mkdir build
   cd build
   ```
2. **Run CMake** to configure the project: 
   ```bash
   cmake ..
   ```
3. **Build the project:**
   ```bash
   make
   ```
4. **Run the tests:**
   ```bash
   ./Tests
   ```

   This will compile the project using CMake, build the necessary binaries, and run the tests located in tests/tests.cpp.
---

## ⚙️ CI Pipelines

Make sure to set up a CI pipeline for automated testing on every push or pull request.

---
