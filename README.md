# Automatic Leetcode Progress Tracker

The README.md is built using mustache, to automatically track your progress in Leetcode

## Installation Instructions
1. run `$ npm init`
2. run `$ npm i mustache`
3. run `$ npm i puppeteer`
4. Enable workflows in your repository on GitHub (repo > Actions > Workflows)
5. Format your README template by editting `main.mustache`
6. In the `leetcode` folder, save your submissions as `<SNo>_<easy/med/hard>_<hyphen-separated-problem-name>.*`
7. Push your changes (remeber to **Pull** first to update your local repository with the README auto-genenerated at the last Push)
8. Run steps 6 and 7 as you solve more questions!

## Preview of the Leetcode Statistics Tracker

Problems Solved: **5**

|Easy| Medium |Hard| 
|:---:|:---:|:---:|
| 1/518 | 3/1067 | 1/429 |

</br>


|#| Title |Difficulty| 
|:---:|:---|:---:|
1 |[Demo Prob](https:&#x2F;&#x2F;leetcode.com&#x2F;problems&#x2F;demo-prob&#x2F;) |![Easy](https:&#x2F;&#x2F;img.shields.io&#x2F;badge&#x2F;Easy-43A047.svg)|
5 |[Demo Prob II](https:&#x2F;&#x2F;leetcode.com&#x2F;problems&#x2F;demo-prob-ii&#x2F;) |![Medium](https:&#x2F;&#x2F;img.shields.io&#x2F;badge&#x2F;Medium-FB8C00.svg)|
42 |[Demo Prob V](https:&#x2F;&#x2F;leetcode.com&#x2F;problems&#x2F;demo-prob-v&#x2F;) |![Medium](https:&#x2F;&#x2F;img.shields.io&#x2F;badge&#x2F;Medium-FB8C00.svg)|
100 |[Demo Prob III](https:&#x2F;&#x2F;leetcode.com&#x2F;problems&#x2F;demo-prob-iii&#x2F;) |![Hard](https:&#x2F;&#x2F;img.shields.io&#x2F;badge&#x2F;Hard-E91E62.svg)|
123 |[Demo Prob IV](https:&#x2F;&#x2F;leetcode.com&#x2F;problems&#x2F;demo-prob-iv&#x2F;) |![Medium](https:&#x2F;&#x2F;img.shields.io&#x2F;badge&#x2F;Medium-FB8C00.svg)|

</br></br>

Check out [this awesome tutorial](https://medium.com/swlh/how-to-create-a-self-updating-readme-md-for-your-github-profile-f8b05744ca91) on self-updating README files.

Check out [this gist](https://gist.github.com/afig/be5ab20c50062dba7cb835e30206659a) on how to create custom badges using [shields.io](http://shields.io).
