<h1> Create integers that cannot be displayed </h1>

In this repository, you will see a C project that I had to do during my 2nd year of Bachelor Degree. This project implements list, AVL tree and hash table. <br>

You will find 3 parts :<br>

- Create an integer that cannot be displayed normally (I will use list of integer)<br>
- Create a tree of big integers (particularly an AVL tree)<br>
- Create a hash table of big integers<br>

<h2> Introduction </h2>

In this project, I will use some lists of integers (included between 0 and 9). Indeed, in C we are limited (as every language) in the type size of numbers. 

<div align="center">
  
| TYPE | SIZE (BITS) | SIZE (BYTES) | SET |
|---|---|---|---|
| CHAR | 8 | 1 | $[ -2^{-7} , 2^{7}-1 ]$ |
| INT | 32 | 4 | $[ -2^{-31} , 2^{31}-1 ]$ |
| FLOAT | 32 | 4 | $[ -2^{-31} , 2^{31}-1 ]$ |
| DOUBLE | 64 | 8 | $[ -2^{-63} , 2^{63}-1 ]$ |
  
</div>
However, there are more type possible (we can add short, long, unsigned, ...), so to see further information click on the link to go <a href="https://en.wikipedia.org/wiki/C_data_types">to the Wikipedia page</a>.<br>

PS : type size can depend of the computer



<h2> Creating list of integers </h2>

To begin, we will create a structure called **cellule** (cell in french) that include an integer and a pointer of "cellule" that it will be used to make a link between the current cell and the next one.<br>
<div align="center">
<img src="https://user-images.githubusercontent.com/106914120/172233169-ad63bec4-039f-488e-b1f2-81703b237b49.png">
</div>

Then, we need to write some functions as :
- CreateList(int element, Liste rest) : Add an element at the beginning of the list
- head(List L) : Get the first element without deleting him
- tail(List L) : Get the list without the first element
- isEmpty(List L)

<table align="center">
  <tr>
    <td>CreateList function</td>
    <td>Head function</td>
  </tr>
  <tr>
    <td><img src="https://user-images.githubusercontent.com/106914120/172234601-e92d11ca-2a88-40af-bd67-0cb198ea0e1f.png"></td>
    <td><img src="https://user-images.githubusercontent.com/106914120/172234638-d4f59179-e646-4d1a-bf2a-d062b1800e76.png"></td>
  </tr>
  <tr>
    <td>Tail function</td>
    <td>isEmpty function</td>
  </tr>
  <tr>
    <td><img src="https://user-images.githubusercontent.com/106914120/172234764-0ee95716-5d7f-492c-89ef-85d687c0d1c5.png"></td>
    <td><img src="https://user-images.githubusercontent.com/106914120/172234791-486b9b55-89de-47da-b3c2-c5dfa32c1ae8.png"></td>
  </tr>
</table>

So now, we can write a function that it creates a big integer. The function consists of asking a string (for example "154987621") that includes a maximum of 199 letters. There is no verification of the string but we could easily do it.

<img src="https://user-images.githubusercontent.com/106914120/172237441-c53e6a7d-ab51-4efd-b974-1ba07e239cf5.png">

<h2> Creating AVL tree of big integer</h2>

Before creating an AVL tree, we should create a normal tree before. So, we need to create another structure called **arbre**. A tree is similar to a list but we have two links (since we are working on binary trees here). 

<div align="center">
<img src="https://user-images.githubusercontent.com/106914120/172237998-96db2ab3-6b20-4bf7-92a5-71a307dc48a0.png">
</div>

In order to save time, we will directly sort the elements in our tree (let's look at the example). 

```mermaid
graph TD;
    15-->10;
    15-->20;
    10-->5;
    10-->13;
    20-->17;
    20-->25;
```
- The left child must be less or equal than the node
- The right child must be greater than the node

<div align="center">
<img src="https://user-images.githubusercontent.com/106914120/172239623-f9a8bc53-2eec-4a8e-a44e-eaf3b2bbf861.png">
</div>

To transform our tree in an AVL tree, we need to some rotations when we add a big integer (since an AVL tree try to minimize the height of the tree that we can see above thanks to "requilibre"). To do that, we need a function which compares two big integers, and rotation function (left, right, left-right, right-left).

<table align="center">
  <tr>
    <td colspan="2" >Comparison function</td>
  </tr>
  <tr>
    <td colspan="2" align="center"><img src="https://user-images.githubusercontent.com/106914120/172242053-29576b2e-c02e-4067-b067-eea085a1adca.png"></td>
  </tr>
  <tr>
    <td>"Balance" function</td>
    <td>Rotation functions</td>
  </tr>
  <tr>
    <td><img src="https://user-images.githubusercontent.com/106914120/172242141-8b2906b4-4155-4b60-a96a-aecf53b1be09.png"></td>
    <td><img src="https://user-images.githubusercontent.com/106914120/172242257-4b643a13-a726-42b0-8bb7-a89453cb604f.png"></td>
  </tr>
</table>

<h2> Creating hash table of big integer</h2>

This final part is by the way the easier part. The first step is to create an array of big integer. Then when we add an element, we will calculate a key in order to calculate an index. Moreover, we have a constant called "theta", it modify the distribution of big integers. So to have the best distribution, we need to have a complex key and a special constant for theta (either $\frac{1+\sqrt{5}}{2}$ or $\frac{\sqrt{5}- 1}{2}$ because it's the golden ratio which have the best distribution).

<table align="center">
  <tr>
    <td>Key calculation function</td>
    <td>Index calculation function</td>
  </tr>
  <tr>
    <td><img src="https://user-images.githubusercontent.com/106914120/172246436-9c772dc7-20c5-4dc4-8423-fb21eb7b76a6.png"></td>
    <td><img src="https://user-images.githubusercontent.com/106914120/172246462-81410de5-be4a-42c3-a4a9-d0720e9c0a9b.png"></td>
  </tr>
</table>
