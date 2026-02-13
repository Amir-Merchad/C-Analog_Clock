# Raylib Analog Clock 🕰️

A real-time analog clock simulation built from scratch using **C** and the **Raylib** library. This project explores procedural 2D rendering, trigonometric time calculation, and audio handling in a low-level environment.

![Project Screenshot](screenshots/demo.png)
*(Note: Please replace `screenshots/demo.png` with an actual screenshot of your running clock)*

## 🚀 Features

* **Real-time Synchronization:** Fetches system time using `time.h` and `struct tm`.
* **Procedural Rendering:** The clock face, ticks, and numbers are drawn mathematically rather than using static assets.
* **Audio Feedback:** Includes a synchronized ticking sound effect for every second passed.
* **Trigonometric Logic:** Hand movements and tick placement are calculated using polar-to-cartesian coordinate conversion.
* **Interactivity:** Clickable link integration to GitHub profile.

## 🛠️ Tech Stack

* **Language:** C (C11 Standard)
* **Library:** [Raylib 5.0](https://www.raylib.com/) (Graphics, Audio, Input)
* **Build System:** CMake 3.21+
* **IDE:** CLion / VS Code

## 🧮 How It Works (The Math)

The core logic involves converting the time (Hours, Minutes, Seconds) into angles, and then converting those angles into 2D screen coordinates $(x, y)$.

### 1. Angle Calculation
The angle $\theta$ is calculated based on the current time unit. For example, the seconds hand moves $\frac{2\pi}{60}$ radians per second.

```c
// -PI/2 shifts the starting point to the top (12 o'clock)
float secondAngle = local->tm_sec * (2 * PI / 60) - PI / 2;
2. Polar to Cartesian ConversionTo draw the hands and tick marks, we convert the angle and radius into coordinate points:$$x = x_{center} + r \cdot \cos(\theta)$$$$y = y_{center} + r \cdot \sin(\theta)$$📦 Installation & BuildPrerequisitesA C Compiler (GCC, MinGW, or MSVC)CMakeRaylib installed on your system (Default path: C:/raylib)ConfigurationThe CMakeLists.txt currently looks for Raylib at C:/raylib. If your installation is different, please update the set(RAYLIB_PATH ...) line in CMakeLists.txt.Building with CMakeBash# Clone the repository
git clone [https://github.com/Amir-Merchad/raylib-analog-clock.git](https://github.com/Amir-Merchad/raylib-analog-clock.git)

# Go into the directory
cd raylib-analog-clock

# Create build directory
mkdir build
cd build

# Configure and Build
cmake ..
cmake --build .
Resource FilesEnsure the resources folder is in the same directory as your executable. It must contain:clock_tick.wav🔮 Future ImprovementsAdd a toggle for Dark/Light mode.Implement a stopwatch or timer feature.Add a smooth interpolation (Lerp) for the second hand so it sweeps instead of ticks.👨‍💻 AuthorAmir MerchadGitHub
### 🛑 Before you push to GitHub:
1.  **Create a folder** named `screenshots` in your project directory.
2.  **Take a screenshot** of your running clock, name it `demo.png`, and put it in that folder.
3.  **Upload the `resources` folder** containing your `.wav` file, or the code will crash for anyon