# GLUtil Header File

## Overview
This repository provides a header file, `glutil.h`, containing utility functions and classes for OpenGL. It includes functionalities for texture management, text rendering, and playing music. The utilities are designed to simplify common tasks in OpenGL programming. Please visit the playlist for further assistance -> https://www.youtube.com/playlist?list=PLxjaJmjQ7asmkEGU6fiG-O6Cj-_ICT63x

## Features
- **Texture Management**: Load and apply textures to OpenGL objects.
- **Text Rendering**: Render static, morphed, and typed text using OpenGL.
- **Music Playback**: Play background music in OpenGL applications.

## Getting Started

### Prerequisites
To use the functionalities provided in this header file, you need to have the following libraries installed:
- OpenGL
- GLUT
- Windows Multimedia System (for music playback)

### Including the Header File
Include the `glutil.h` file in your project:

```cpp
#include "glutil.h"
```

## Usage

### Texture Management
Load and apply textures to OpenGL objects using the `TextureInfo` class and related functions.

#### Loading a Texture
```cpp
loadImageAndStore("path/to/your/image.bmp");
```

#### Applying a Texture
```cpp
ApplyTexture(x1, y1, x2, y2, x3, y3, x4, y4, textureID);
```

### Text Rendering
Render static, morphed, and typed text on your OpenGL window.

#### Static Text
```cpp
staticText("Hello, World!", 100, 200, 0.1f, 2, 1.0f, 1.0f, 1.0f);
```

#### Morphed Text
Update and render morphed text:
```cpp
morphedText("Welcome!", 100, 200, 0.1f, 2, 1.0f, 1.0f, 1.0f);
glutTimerFunc(100, mT_update, 0);  // Start the morphing update timer
```

#### Typed Text
Render typed text with a typing animation:
```cpp
typedText(100, 200, "Typing this text...");
glutTimerFunc(100, _keyboard_timer, 0);  // Start the typing update timer
```

### Music Playback
Play background music in your OpenGL application:
```cpp
PlayMusic("path/to/your/music.wav");
```

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contributions
Contributions are welcome! Feel free to submit issues and pull requests to enhance the functionalities provided by this header file.

## Authors
- Wahiduzzaman Shuvo
- Imtiaj Sajin 
- Esme Abha 
## Acknowledgments
- OpenGL and GLUT communities for their extensive documentation and tutorials.
- Stack Overflow and other online forums for troubleshooting and inspiration.

