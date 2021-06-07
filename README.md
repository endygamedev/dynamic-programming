<h1 align="center"><code>«Favorites dynamic programming problems»</code></h1>
<p align="right">
  <a href="https://github.com/endygamedev/dynamic-programming/actions/workflows/main.yml"><img src="https://github.com/endygamedev/dynamic-programming/actions/workflows/main.yml/badge.svg"></a>
  <a href="#contributors"><img alt="Contributors" src="https://img.shields.io/github/contributors/endygamedev/dynamic-programming?color=blue"></a>
</p>

A module for Python in C that solves some dynamic programming problems.

<details open>
  <summary> <b> <img src="./assets/parrot.gif" alt="parrot" width="25"/> Table of content </b> </summary>
  <ol>
    <li><b><a href="#algorithms" id="table_algorithms">Algorithms</a></b></li>
    <li><b><a href="#module" id="table_module">Module</a></b></li>
    <li><b><a href="#contributors" id="table_contributors">Contributors</a></b></li>
    <li><b><a href="#license" id="table_license">License</a></b></li>
  </ol>
</details>

<a id="algorithms" href="#table_algorithms"><h2>Algorithms</h2></a>

The selected tasks are the following tasks.

<details>
  <summary> 1. <a href="./src/basic-implementation/knapsack.c">0–1 Knapsack problem</a> </summary>
      <h6>Short description</h6>
      <p>In the <b>0–1 Knapsack problem</b>, we are given a set of items, each with a weight and a value, and we need to determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible.</p>
      <h6> View full on <a href="https://en.wikipedia.org/wiki/Knapsack_problem">Wiki</a> </h6>
</details>

<details>
  <summary> 2. <a href="./src/basic-implementation/rod-cutting-problem.c">Rod Cutting Problem</a> </summary>
      <h6>Short description</h6>
      <p>Given a rod of length <code>n</code> and a list of prices of rods of length <code>i</code>, where <code>1 &lt;= i &lt;= n</code>, find the optimal way to cut the rod into smaller rods to maximize profit.</p>
      <h6> View full on <a href="https://en.wikipedia.org/wiki/Cutting_stock_problem">Wiki</a> </h6>
</details>

<details>
  <summary> 3. <a href="./src/basic-implementation/coin-change-problem.c">Coin Change Problem</a> </summary>
      <h6>Short description</h6>
      <p>Given an unlimited supply of coins of given denominations, find the total number of distinct ways to get the desired change.</p>
      <h6> View full on <a href="https://en.wikipedia.org/wiki/Change-making_problem">Wiki</a> </h6>
</details>

<details>
  <summary> 4. <a href="./src/basic-implementation/coin-change-making.c">Coin Change-Making Problem</a> </summary>
      <h6>Short description</h6>
      <p>Given an unlimited supply of coins of given denominations, find the minimum number of coins required to get the desired change. That is, you need to find the minimum number of coins to exchange and withdraw this set. </p>
      <h6> View full on <a href="https://en.wikipedia.org/wiki/Change-making_problem">Wiki</a> </h6>
</details>

<details>
  <summary> 5. <a href="./src/basic-implementation/levenshtein-distance.c">The Levenshtein Distance Problem</a> </summary>
      <h6>Short description</h6>
      <p>Edit distance is a way of quantifying how different two strings are from one another by counting the minimum number of operations required to transform one string into the other.</p>
      <h6> View full on <a href="https://en.wikipedia.org/wiki/Levenshtein_distance">Wiki</a> </h6>
</details>

<details>
  <summary> 6. <a href="./src/basic-implementation/matrix-chain-multiplication.c">Matrix Chain Multiplication Problem</a> </summary>
      <h6>Short description</h6>
      <p><b>Matrix chain multiplication</b> is an optimization problem concerning the most efficient way to multiply a given sequence of matrices. The problem is not actually to perform the multiplications, but merely to decide the sequence of the matrix multiplications involved.</p>
      <h6> View full on <a href="https://en.wikipedia.org/wiki/Matrix_chain_multiplication">Wiki</a> </h6>
</details>

<details>
  <summary> 7. <a href="./src/basic-implementation/minimum-cost-to-reach-the-last-cell.c">Minimum Cost to Reach Last Cell of Matrix From Its First Cell Problem</a> </summary>
      <h6>Short description</h6>
      <p>Given an <code>M × N</code> matrix where each cell has a cost associated with it, find the minimum cost to reach the last cell <code>(M-1, N-1)</code> of the matrix from its first cell <code>(0, 0)</code>. We can only move one unit right or one unit down from any cell, i.e., from cell <code>(i, j)</code>, we can move to <code>(i, j+1)</code> or <code>(i+1, j)</code>.</p>
      <h6> View full on <a href="https://www.techiedelight.com/find-minimum-cost-reach-last-cell-matrix-first-cell/">Wiki</a> </h6>
</details>

<details>
  <summary> 8. <a href="./src/basic-implementation/const-cost-to-reach-the-last-cell.c">Const Cost to Reach Last Cell of Matrix From Its First Cell Problem</a> </summary>
      <h6>Short description</h6>
      <p>Find the number of paths of a given cost from the upper left to the lower right element of the matrices.</p>
</details>

<details>
  <summary> 9. <a href="./src/basic-implementation/minimum-sum-partition-problem.c">Minimum Sum Partition Problem</a> </summary>
      <h6>Short description</h6>
      <p>Given a set of positive integers <code>S</code>, partition set <code>S</code> into two subsets, <code>S1</code> and <code>S2</code>, such that the difference between the sum of elements in <code>S1</code> and the sum of elements in <code>S2</code> is minimized.</p>
      <h6> View full on <a href="https://en.wikipedia.org/wiki/Partition_problem">Wiki</a> </h6>
</details>

<details>
  <summary> 10. <a href="./src/basic-implementation/n-digit-binary-strings-without-ones.c">Find All N-digit Binary Strings Without Any Consecutive 1's Problem</a> </summary>
      <h6>Short description</h6>
      <p>Given a positive integer <code>n</code>, count all n–digit binary strings without any consecutive <code>1's</code>.</p>
      <h6> View full on <a href="https://www.techiedelight.com/find-n-digit-binary-strings-without-consecutive-1s/">Wiki</a> </h6>
</details>

<a id="module" href="#table_module"><h2>Module</h2></a>
The task is decomposed into three modules:
<ol>
    <li><a href="./src/python-modules/change-making">Change-Making Problem</a></li>
    <li><a href="./src/python-modules/knapsack">Knapsack Problem</a></li>
    <li><a href="./src/python-modules/knapsack">FDPP (other problems)</a></li>
</ol>


<h3>Install</h3>
<pre>
$ ./run
</pre>

And also you can instant test installed packages

<h3>Usage</h3>
<pre>
import fdpp
import knapsack
import change_making
</pre>

<a id="contributors" href="#table_contributors"><h2>Contributors</h2></a>

<table>
  <tr>
    <td><img alt="egor bronnikov" src="https://avatars.githubusercontent.com/u/52889537?v=4" width="40"></td>
    <td><img src="./assets/parrot.gif" alt="parrot" width="25"/> <a href="https://github.com/endygamedev">Egor Bronnikov</a></td>
  </tr>
  <tr>
    <td><img alt="roman postolnik" src="https://avatars.githubusercontent.com/u/60935386?v=4" width="40"</td>
    <td><img src="./assets/parrot.gif" alt="parrot" width="25"/> <a href="https://github.com/arti-shok">Roman Postolnik</a></td>
  </tr>
</table>


<a id="license" href="#table_license"><h2>License</h2></a>

<code>dynamic-programming</code> provided under the terms of the GPL-3.0 license.
See the [LICENSE](./LICENSE) files for details.

<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a>

<br>
<p align="center">
    :arrow_up: <a href="#"><b>Back to top</b></a> :arrow_up:
</p>

---

<p align="center">
  <sub><a href="https://endygamedev.github.io">:man_technologist: endygamedev</a></sub>
</p>
