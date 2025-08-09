# 🌌 miniRT - 1337 Project

[![1337 Badge](https://img.shields.io/badge/1337-Project-blue)](https://www.42network.org/)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)
![Grade](https://img.shields.io/badge/Grade-125%2F100-success)

---

## 📜 Project Overview

**miniRT** is a core graphics project in the **1337 curriculum** (42 Network) focused on building a minimal ray tracer. The goal is to render realistic 3D scenes using ray tracing techniques, supporting spheres, planes, cylinders, cones, and advanced lighting. The project leverages the modern [MLX42](MLX42/README.md) graphics library for cross-platform rendering and interactive controls.

> This project introduces the fundamentals of **ray tracing**, **mathematics for 3D rendering**, and **lighting models** by building a minimalistic real-time 3D renderer from scratch.

You will learn to:
- Parse and validate scene files.
- Implement **ray-object intersection algorithms**.
- Apply the **Phong lighting model** for realistic shading.
- Manage transformations (translation, rotation, scaling).
- Use **MiniLibX** for window creation and pixel manipulation.

---

## 🚀 Features

### ✅ Mandatory Part
- **Scene Parsing**: Load `.rt` files describing objects, lights, and camera.
- **Primitives**:
  - Sphere
  - Plane
  - Cylinder
- **Lighting**:
  - Ambient light
  - Point light
  - Diffuse & Specular reflection (Phong model)
- **Camera**:
  - Viewport setup
  - Ray generation for each pixel
- **Rendering**:
  - Ray casting and intersection detection
  - Closest object hit calculation
  - Basic shadows
- **MiniLibX Integration**:
  - Window display
  - Pixel drawing

### 🌟 Bonus Part
- **Extra Primitives**:
  - Cone
  - Other complex shapes if desired
- **Advanced Effects**:
  - Multiple lights
  - Reflections
  - Refractions
  - Transparency
- **Textures & Patterns**:
  - Checkerboard pattern
  - Image texture mapping (UV mapping)
  - Bump mapping for surface detail
- **Camera Controls**:
  - Mouse and keyboard interactions
  - Real-time rotation, translation, zoom

---

## 🖥️ How to Build & Run

### 1. Clone the Repository
```bash
git clone https://github.com/Mohaben-1/42-miniRT_1337.git
cd 42-miniRT_1337
```

### 2. Compile the Program  

- **dependencies:**
  If your system has neither GLFW nor CMake its highly recommended you use brew to install those missing dependencies.
```bash
  brew install glfw
  brew install cmake
```
Use the provided `Makefile` to compile:  
- **Without Bonus**  
  ```bash  
  make  
  ```  

- **With Bonus**  
  ```bash  
  make bonus
  ```  

### 3. Run the Program

The executable takes a scene file as an argument. scenes files are provided in the scenes (for mandatory) and scenes_bonus (for bonus) directory.

```bash
./minirt scenes/example.rt
```

Press ESC or close the window to exit.

---

## 🛠️ Tools & Technologies

- **Language**: C (ISO C99)
- **Graphics Library**: [MiniLibX](https://github.com/codam-coding-college/MLX42)
- **Math**:
  - Vector algebra
  - Dot & cross product
  - Normal calculation
- **Rendering Algorithm**: Ray tracing
- **Lighting Model**: Phong illumination
- **Parsing**: Custom tokenizer & validator for `.rt` files
- **Development Environment**: macOS/Linux (X11 for MLX)

---

## 📂 Repository Structure

```plaintext
|-- mandatory/                # Core implementation
|   |-- check/                # Scene validation
|   |-- includes/             # Headers
|   |-- main.c                # Entry point
|   |-- math/                 # Vector & math utilities
|   |-- mlx_utils/            # MLX42 helpers
|   |-- parsing/              # Scene file parsing
|   |-- rendring/             # Ray tracing and rendering
|   |-- utils/                # General utilities

|-- Bonus/                    # Bonus implementation
|   |-- check_bonus/
|   |-- includes_bonus/
|   |-- main_bonus.c
|   |-- math_bonus/
|   |-- mlx_utils_bonus/
|   |-- parsing_bonus/
|   |-- rendring_bonus/
|   |-- utils_bonus/

|-- MLX42/                    # MLX42 graphics library (submodule)
|-- bumps/                    # PNG textures for bump mapping
|-- scenes/                   # Example scene files
|-- scenes_bonus/             # Bonus scenes
|-- Makefile                  # Build rules
|-- README.md                 # Documentation
```  

---

## 📝 Scene File Format (.rt)
Example:

```plaintext

A 0.2 255,255,255
C 0,0,0 0,0,1 70
L 10,0,0 0.6 255,255,255
sp 0,0,20 20 255,0,0
pl 0,-5,0 0,1,0 0,255,0
cy 50,0,20 0,1,0 14.2 21.42 10,0,255
```
Legend:

A: Ambient light (ratio, RGB)

C: Camera (position, direction, FOV)

L: Light (position, brightness, RGB)

sp: Sphere (position, diameter, RGB)

pl: Plane (position, normal, RGB)

cy: Cylinder (position, normal, diameter, height, RGB)


---

## 📖 Key Concepts

### 1️⃣ Ray Tracing
Ray tracing simulates the way light rays travel in a scene:
- A ray is cast from the **camera** through each **pixel**.
- It checks intersections with objects in the scene.
- The closest intersection point is shaded according to the lighting model.

---

### 2️⃣ Ray-Object Intersection
Each primitive has its own mathematical formula:
- **Sphere**: Solve quadratic equation from ray-sphere equation.
- **Plane**: Solve for `t` in ray-plane equation using dot product.
- **Cylinder**: Solve using vector projection & quadratic formula.
- **Cone** *(bonus)*: Similar to cylinder but with varying radius.

---

### 3️⃣ Lighting - Phong Illumination Model
The final pixel color is computed as:
	color = ambient + diffuse + specular

- **Ambient**: Constant light everywhere.
- **Diffuse**: Light scattered from a surface (Lambert's cosine law).
- **Specular**: Mirror-like highlights (depends on viewer position).

---

### 4️⃣ Shadows
A secondary **shadow ray** is cast from the hit point toward each light:
- If it hits another object before the light → point is in shadow.

---

### 5️⃣ UV Mapping & Textures (Bonus)
- **UV Mapping**: Convert 3D point → 2D coordinates on a texture.
- **Checkerboard**: Procedural texture based on object coordinates.
- **Bump Mapping**: Alters surface normals to simulate fine detail.

---

## 🎨 Rendering and Ray Tracing Pipeline

### Rendering Algorithm
The program uses a **ray tracing** algorithm to calculate the color of each pixel on the screen by simulating how rays of light travel through a scene.  
For every pixel:
- A **ray** is generated from the **camera** through the pixel into the scene.
- The ray is tested for intersections with all objects.
- The **closest intersection** is determined.
- Lighting calculations are applied to determine the pixel’s final color.

This approach ensures realistic shading, shadows, and effects, even for complex shapes.

---

## 📖 Ray Tracing Concepts

### Idea Behind Ray Tracing:
- The main goal is to **simulate light** in a way that produces realistic images.
- Every pixel is computed individually, based on **physics-like calculations** of light and object interaction.
- It supports shadows, reflections, and refractions naturally by casting additional rays when needed.

---

### Understanding the Key Concepts

#### 1. **Primary Rays**
A **primary ray** starts from the camera’s position and passes through the center of each pixel on the image plane.  
Its equation can be expressed as: P(t) = O + tD

Where:
- `O` is the ray origin (camera position)
- `D` is the ray direction (normalized)
- `t` is a scalar distance along the ray
- `P(t)` is a point in 3D space

---

#### 2. **Ray-Object Intersection**
For each object type, we have a specific intersection equation:

- **Sphere**: Derived from substituting the ray equation into the sphere’s equation and solving the quadratic formula.
- **Plane**: Solved by checking when the ray direction is not parallel and finding `t` using the dot product.
- **Cylinder**: Involves projecting the ray onto the cylinder’s axis and solving for `t`.
- **Cone** *(bonus)*: Similar to a cylinder but with a radius that changes with height.

If `t` is negative, the intersection is behind the camera and is discarded.  
The smallest positive `t` is chosen for rendering.

---

#### 3. **The Phong Lighting Model**
The **Phong Illumination Model** is used to calculate the color at the intersection point:
	color = ambient + diffuse + specular

- **Ambient**: Constant light present everywhere in the scene.
- **Diffuse**: Light scattered from a surface, depends on the angle between the light and the surface normal (Lambert's cosine law).
- **Specular**: Bright highlights, depends on the viewer's position and shininess factor.

---

#### 4. **Shadows**
Shadows are computed by casting a **shadow ray** from the intersection point toward each light source:
- If the shadow ray intersects another object before reaching the light, the point is in shadow for that light.
- Only ambient light contributes in shadowed areas (no diffuse or specular).

---

#### 5. **Reflection and Refraction (Bonus)**
- **Reflection**: A new ray is cast in the mirror-reflected direction from the hit point.
- **Refraction**: Light passes through transparent materials, bending according to Snell’s law.
- These effects require recursive ray tracing to gather light from multiple bounces.

---

#### 6. **UV Mapping and Textures (Bonus)**
- **UV Mapping**: Converts 3D coordinates into 2D texture coordinates.
- **Checkerboard Pattern**: A procedural effect using object coordinates to alternate colors.
- **Bump Mapping**: Alters the surface normal before lighting calculations, giving the illusion of detail without changing the geometry.

---

### Summary of the Ray Tracing Process:
1. For each pixel:
   - Generate a ray from the camera.
   - Find the closest object intersection.
2. If there is an intersection:
   - Compute the surface normal.
   - Apply the lighting model (ambient + diffuse + specular).
   - Cast shadow rays for shadows.
   - (Bonus) Cast reflection/refraction rays if needed.
3. If there is no intersection:
   - Use the background color.
4. Repeat for all pixels to produce the final image.

---

## 🌟 Achievements  

- Built a complete ray tracing engine from scratch.
- Implemented Phong lighting and realistic shadows.
- Added advanced texturing and bump mapping for realism.
- Developed robust .rt file parsing with strict validation.
- Fully functional interactive camera (bonus).

---

## 🛡️ Makefile Targets  

- `make` – Compiles the program.
- `make bonus` – Compiles the bonus program.
- `make clean` – Removes object files.
- `make fclean` – Removes object files and the executable.
- `make re` – Cleans and recompiles everything.

---

## 📚 References
- [scratchapixel.com](https://www.scratchapixel.com/) The famous and inevitable scratch pixel website
- [cosinekitty.com](http://cosinekitty.com/raytrace/raytrace_us.pdf) - The book Fundamentals of Ray Tracing
- [gabrielgambetta.com](https://www.gabrielgambetta.com/computer-graphics-from-scratch/02-basic-raytracing.html) - Basic Raytracing
- [graphics.cs.cmu.edu](http://graphics.cs.cmu.edu/nsp/course/15-462/Spring04/slides/09-texture.pdf) - Texture and other Mappings
- [ics.uci.edu](https://www.ics.uci.edu/~majumder/VC/classes/BEmap.pdf) - Bump and Environmen Mapping
- [aurelienbrabant.fr](https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx#finding-the-pixels-first-bytes-address) - Pixel drawing with the minilibx
- A few post on slackoverflows, wikipedia pages and other websites

---

## 🛡️ License 

This project is part of the 1337 curriculum. It is shared here for educational purposes and should not be used for plagiarism.
