# Oeuvre-Engine

![b0ed0bd0-848b-4a1a-9124-f1d8514a0071](https://github.com/user-attachments/assets/5424f179-a02d-4943-872d-95d5ff51143f)

Oeuvre is an early-stage game engine that I am developing primarily for educational and experimental purposes.

### Current features
- IBL PBR
- Deferred shading
- Omnidirectional shadows
- Cascaded shadows
- Physics (WIP)
- Tone mapping
- Frustum culling
- HDRI skyboxes
- Skeletal animation and basic character movement

### Controls
WASD: camera/character movement<br>
C: toggle viewport mode<br>
Q: toggle gizmo local/world mode<br>
W/E/R: select gizmo translate/rotate/scale operation<br>
F: throw a cube (physics demo)<br>
F11: toggle fullscreen (borderless window)

### Screenshots

<img width="1477" height="1226" alt="Screenshot 2025-10-29 175518" src="https://github.com/user-attachments/assets/fd6d0390-17f3-4247-b5c6-6e228f4505cc" />

### Download

The .lib and .dll files are managed by LFS. Download via terminal:

```
git lfs install
git clone https://github.com/JxhnStoner/Oeuvre-Engine.git
```

### Build

To create a Visual Studio 2022 solution run "GenerateProjects.bat".
