
<a name="readme-top"></a>




[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]



<!-- PROJECT LOGO -->
<br />
<div align="center">

  <h3 align="center">Hello Hong Kong</h3>

  <p align="center">
    A local RPG game that is full of memes!
    <br />
    <a href="https://github.com/MartinYu0510/Engg1340_Project"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/MartinYu0510/Engg1340_Project/issues">Report Bug</a>
    ·
    <a href="https://github.com/MartinYu0510/Engg1340_Project/issues">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
  <li><a href="#about-the-game">About The Game</a></li>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <ul>
        <li><a href="#windows">Windows</a></li>
        <li><a href="#linux">Linux</a></li>
        <li><a href="#macOS">macOS</a></li>
      </ul>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->
## About The Game


<!-- ABOUT THE PROJECT -->
## About The Project

[![Product Name Screen Shot][product-screenshot]](https://example.com)

As a typical local student in Hong Kong, we were thinking of making a game that can catch current's trend. To highlight the 


<p align="right">(<a href="#readme-top">back to top</a>)</p>



### Built With

- 100% C++ [![CPP][CPP.com]][cpp-url]
- 200% Love
- 300% Stress

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

Although this project will be marked using Ubuntu server in HKU, you can still use it in any system

### Prerequisites

<!-- WINDOWS -->
#### Windows
A compiler is required to compiler the cpp files. Here we will recommend users to setup with MingW. Here is the modified guide, originally written by [Microsoft Inc.](https://code.visualstudio.com/docs/cpp/config-mingw).

1.  Get the latest version of Mingw-w64 via  [MSYS2](https://www.msys2.org/), which provides up-to-date native builds of GCC, Mingw-w64, and other helpful C++ tools and libraries. You can download the latest installer from the MSYS2 page or use this  [link to the installer](https://github.com/msys2/msys2-installer/releases/download/2022-06-03/msys2-x86_64-20220603.exe).
2. Follow the  **Installation**  instructions on the  [MSYS2 website](https://www.msys2.org/)  to install Mingw-w64. Take care to run each required Start menu and  `pacman`  command.
3. Install the Mingw-w64 toolchain (`pacman -S --needed base-devel mingw-w64-x86_64-toolchain`). Run the  `pacman`  command in a MSYS2 terminal. Accept the default to install all the members in the  `toolchain`  group.
4. install make
	```pwsh
	winget install GnuWin32.Make
	```
5. Add the path to your Mingw-w64  `bin`  folder and the path to  your GnuWin32 file to the Windows  `PATH`  environment variable by using the following steps:

	1.  In the Windows search bar, type 'settings' to open your Windows Settings.
	2.  Search for  **Edit environment variables for your account**.
	3.  Choose the  `Path`  variable in your  **User variables**  and then select  **Edit**.
	4.  Select  **New**  and add the Mingw-w64 destination folder path to the system path. The exact path depends on which version of Mingw-w64 you have installed and where you installed it. If you used the settings above to install Mingw-w64, then add this to the path:  `C:\msys64\mingw64\bin`; If you used the settings above to install GnuWin32.Make, then add this to the path: `C:\Program Files (x86)\GnuWin32\bin`
	5.  Select  **OK**  to save the updated PATH. You will need to reopen any console windows for the new PATH location to be available.
6. install make
	```pwsh
	winget install GnuWin32.Make
	```

<!-- LINUX -->
#### Linux
Linux systems are easier to setup the g++ environment.
1. Install g++ and makefile in terminal
	```sudo apt install build-essential```
2. Install make to rune makefile
	```sudo apt install make```
2. Press enter for any asked questions.
3. Done!

<!-- MACOS -->
#### MacOS
~~As a typical engineer, I don't use MacBooks. So, we will NOT provide any support here.~~
<sub><sup>Use Windows, OK?😉</sup></sub>

### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/MartinYu0510/Engg1340_Project.git
   ```
2. In the destination file, compile the code using makefile
	   ```sh
	   make
	   ```
3. run the game `main`
   ```sh
   ./main
   ```

<p align="right">(<a href="#readme-top">back to top</a>)</p>




<!-- ROADMAP -->
## Roadmap

- [ ] Add Changelog
- [ ] Better CLI Ux
- [ ] Add More ASCII arts
- [ ] Multi-language Support
    - [ ] Trad. Chinese
    - [ ] Cantonese
- [ ] GUI

See the [open issues](https://github.com/MartinYu0510/Engg1340_Project/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "IMPROVEMENT".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/IMPROVEMENT`)
3. Commit your Changes (`git commit -m 'Add some IMPROVEMENT'`)
4. Push to the Branch (`git push origin feature/IMPROVEMENT`)
5. Open a Pull Request

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Your Name - kc072015@connect.hku.hk

Project Link: [https://github.com/MartinYu0510/Engg1340_Project](https://github.com/MartinYu0510/Engg1340_Project)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

Use this space to list resources you find helpful and would like to give credit to. I've included a few of my favorites to kick things off!

* [Choose an Open Source License](https://choosealicense.com)
* [GitHub Emoji Cheat Sheet](https://www.webpagefx.com/tools/emoji-cheat-sheet)
* [Malven's Flexbox Cheatsheet](https://flexbox.malven.co/)
* [Malven's Grid Cheatsheet](https://grid.malven.co/)
* [Img Shields](https://shields.io)
* [GitHub Pages](https://pages.github.com)
* [Font Awesome](https://fontawesome.com)
* [React Icons](https://react-icons.github.io/react-icons/search)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
[contributors-shield]: https://img.shields.io/github/contributors/MartinYu0510/Engg1340_Project?style=for-the-badge
[contributors-url]: https://github.com/MartinYu0510/Engg1340_Project/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/MartinYu0510/Engg1340_Project?style=for-the-badge
[forks-url]: https://github.com/MartinYu0510/Engg1340_Project/network/members
[stars-shield]: https://img.shields.io/github/stars/MartinYu0510/Engg1340_Project?style=for-the-badge
[stars-url]: https://github.com/MartinYu0510/Engg1340_Project/stargazers
[issues-shield]: https://img.shields.io/github/issues/MartinYu0510/Engg1340_Project?style=for-the-badge
[issues-url]: https://github.com/MartinYu0510/Engg1340_Project/issues
[product-screenshot]: images/New Facilities.gif
[CPP.com]: https://img.shields.io/badge/-c++-black?logo=c%2B%2B&style=for-the-badge
[cpp-url]: https://isocpp.org/
