# Dijkstra-Simulator

<div id="top"></div>

[![LinkedIn][linkedin-shield]][linkedin-url]

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
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
      </ul>
    </li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

<span><img src="HowItSpawns.PNG" alt="drawing" width="400"/> <img src="gifDemo.gif" alt="drawing" width="400"/></span>

This is one of my first projects in C ++, realized to put into practice the Dijktra algorithm, which takes in input a weighted Graph (in this case not oriented) and returns the shortest path tree. 
Node 0 is used as the source node, but of course you can change the source at any time ;)

How it works:
* Firstly, it takes as input a set of nodes and weights
* Once started you can reposition the nodes within the window area dragging them across the screen with the mouse cursor(hold left click)
* When you are happy with the look of the graph, you can go ahead and right click on "Exec Dijkstra" Button

You can change the animation speed and the sleep time of the thread that calculates dijkstra, making it faster or slower.
I've tried using big and complicated graphs and it works quite well, you can try it yourself!


### Built With

It's a pure C++ project. I've used a graphic library called SFML, really easy to use!

* See the documentation at [SFML](https://www.sfml-dev.org/)


<!-- GETTING STARTED -->
## Getting Started

Just clone the repository, install the following library, and run it in your IDE.

### Prerequisites

You only need to install one librabry to make it work:
* Installation guide: [SFML](https://www.sfml-dev.org/tutorials/2.5/start-vc.php)
  
<!-- ROADMAP -->
## Roadmap

- [x] Add Animation
- [x] Add dijkstra exec button
- [] Add MST calculator
- [] Add graphic interface to choose witch node to start from calculating shortest path tree


<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/david-ambros-07404a174/
[product-screenshot]: images/screenshot.png
