# **XML to JSON**

### (GUI application that converts XML to JSON)


![](https://i.imgur.com/9ZUTgXQ.png)

# **Table of Contents**

1. [1. Table of Contributions](#Table-of-Contributions)
2. [Background](#Background)
3. [Implementation Details](#Implementation-Details)<br><details>
        1.[trim Function ](#trim-Function)<br>
        2.[Open_file Function](#Open_file-Function)<br>
        3.[line_numer Function](#line_numer-Function)<br>
        4.[check Function](#check-Function)<br>
        5.[correct_string Function](#correct_string-Function)<br>
        6.[tree Function](#tree-Function)<br>
        7.[calc_height Function](#calc_height-Function)<br>
        8.[ident Function](#ident-Function)<br><summary>Click here to show all functions</summary>
        9.[same_childs Function](#same_childs-Function)<br>
        10.[conv_children Function](#conv_children-Function)<br>
        11.[tree_to_json Function](#tree_to_json-Function)<br>
        12.[encode Function](#encode-Function)<br>
        13.[decode Function](#decode-Function)<br>
        14.[conv_children_comp Function](#conv_children_comp-Function)<br>
        15.[decode_json Function](#decode_json-Function)<br></details>
4. [GUI Layout](#GUI-Layout)
5. [List of References](#List-of-References)
6. [End](#End)



<div id='Table-of-Contributions'/>

## **Table of Contributions**


| Name  |
| ------------ |
|  [Aya tallah Tarek](https://github.com/ayatarek831) |
| [Moaz Ayman]()  |
|  [Moatsm Tarek](https://github.com/Moatsm-prog) |
|  [Muhammad Ahmad](https://github.com/ZeusDes)|
|  [Mustafa Amer](https://github.com/MustafaAmer-1) |


<div id='Background'/>

## **Background**
This app is mainly made to convert an XML file into a JSON file. This mainly depends on converting the XML file into tree structure which makes this conversion easier.

The app checks for input XML consistency and give the user a choice whether to Autocorrect errors or No, It also provides many other options like prettifying the unformatted input file, beside that it can convert XML to JSON, compress both XML and JSON files, and Decompress files already compressed by the app, the compressed XML files are saved in “dxml” extension, similarly, the compressed JON files are saved in “dson” extension.

The app also has the option to zoom in or out by moving a slider. Also there are some shortcuts implemented in the app such as:
- 	 (Ctrl + S) for saving files.
- 	 (Ctrl + O) for opening files.

Beside that there is a status bar at the bottom of the app which previews the type of input file.

In order to create that application, we mainly wrote the backend functions using C++, then we created the GUI layout using QT creator.

<div id='Implementation-Details'/>

## **Implementation Details**


------------

<div id='trim-Function'/>


## **trim Function**
- 	**Parameters of the function:**
    - const string& s: This is the string we need to remove form it the whitespaces.
- 	**Return type:**
    - string: the function returns string without whitespaces.
- **How it works:**
    - he function removing whitespaces from left and right part of the string by count the whitespaces of the left part in the first while loop and count the whitespaces of the right part in the second while loop and then use substr() to remove this spaces from our string.
- 	**Role in the code:**
    - The function helps in removing the whitespaces from the xml file 
- **Asymptotic Analysis:**
    - Assuming the string length of n.

|  Time Complexity | O(n)  |
| ------------ | ------------ |
| **Space Complexity**  | **O(n)**  |

------------

<div id='Open_file-Function'/>


## **Open_file Function**

- 	**Parameters of the function:**
    -  String path: this string is the name of the path of the file that we need to open.
- 	**Return type:**
    - String: the function returns the content of the file in string variable.
- **How it works:**
    - The function first open the XML file then take line by line and remove the whitespaces by using trim function then return the content of the file in string and then close the file.
- 	**Role in the code:**
    - The function help in change the content of xml file to string to make it easy to make operation on it.
    - Assuming m is the size of the file, n is the length of the each line and x is the length of the returned string.

|   | Best case  |  Worst case |
| ------------ | ------------ | ------------ |
|  Time Complexity |  O(1) |  O(n) |
|  Space Complexity|  O(n) |  O(n) |

------------
<div id='line_numer-Function'/>


## **line_numer Function**

- **Parameters of the function:**
    - int indx: this int is the index where the error found in the check function.
- **Return type:**
    - int: the function returns the place where the error exists in the xml file.
- **How it works:**
    - This function take the index where the error found in the string to find it in the XML file to return its place in the XML
- **Role in the code:**
    - The function help in found the place where the error exists in the xml file.
- **Asymptotic Analysis:**
    -  Assuming m is the size of the file and n is the length of the each line.

|   | Best case  |  Worst case |
| ------------ | ------------ | ------------ |
|  Time Complexity |  O(1) |  O(n*m) |
|  Space Complexity|  O(1) |  O(1) |
------------
<div id='check-Function'/>


## **check Function**

- **Parameters of the function:**
    - It does not take parameters.
- **Return type:**
    -  Void.
- **How it works:**
    - this function used to check if the XML file includes any errors or not by using stack to push the opening tag and if the closed  tag same as the top in the stack it pop the top of the stack  else if we found error the function throw an exception
- **Role in the code:**
    - The function helps in check if the xml file contains errors or not for xml consistency.
-  **Asymptotic Analysis:**
    - Assuming m is the size of xml (string) and n is the number of the opining tags.

|   | Best case  |  Worst case |
| ------------ | ------------ | ------------ |
|  Time Complexity |  O(1) |  O(n) |
|  Space Complexity|  O(1) |  O(m) |

------------

<div id='correct_string-Function'/>


## **correct_string Function**

- **Parameters of the function:**
    - string Original_file: this string is the content of the xml file.  
-** Return type:**
    - string: return the correct string that contains the original content of the xml file.
- **How it works:**
    - this function used to correct the XML file if it contain any errors by using string and stack, it loop on the string Original_file and if it found opening tag we push it on the stack and add it to the string else if it is closed tag and the same as the top of stack we pop it and add it to string and if it is not opening or closed tag we add it to the string and then return this string.   
- **Role in the code:**
    - The function helps in correct the xml file if it contains any errors.
    -  Note: the correction here is on the general case (the correction produces a valid xml file but not necessarily logically correct and that is why functionality of program is disabled for corrected files).
-  **Asymptotic Analysis:**
    - Assuming m is the length of Original_file, n is the number of the opining tags and s is the size of string that will return from the function.


|  Time Complexity | O(m)  |
| ------------ | ------------ |
| **Space Complexity**  | **O(n+s)**  |

------------

<div id='tree-Function'/>

## **tree Function**

- **Parameters of the function:**
     - rom (int): the index in the string we want to start at it.
    -  oot (Node*): the parent node we want to find its children.
    -  Xml (String): the string containing xml file we want to generate tree to it,
- **Return type:**
     -  int: the function returns the index of character after the last tag processed by the function.
- **How it works:**
    -  The function builds an xml tree recursively by finding the children of each node.
    - Each recursive function must have a base step which steps the function calling itself at some limit and the base step here is that we find a closing tag.
    -  The function iterates on the xml string starting from the index given in the parameters in the function and stores any opening tag it finds in the vector of childs of the root node given in the parameters.
    -  We call the function recursively on each child until we reach the leaf of the tree.
- **Role in the code:**
    -  The function converts our xml string into a tree which is much easier to be processed to form JSON file,
- **Asymptotic Analysis:**
    -  Assuming n be the number of opening tags in the xml file. 

|  Time Complexity | O(n)  |
| ------------ | ------------ |
| **Space Complexity**  | **O(n^2)**  |

------------
<div id='calc_height-Function'/>

## **calc_height Function**

- **Parameters of the function:**
    - root (Node*): the root of the tree we want to calculate its height.
- **Return type:**
    - void:  the function does not return anything but it sets the height of each node. 
- **How it works:**
 - The function iterates on the tree recursively until we reach the leaf nodes of the tree.
    - The leaf nodes heights are set to zero (base step)) and the returned height from each function is increased by one at the previous call to the function until we reach to the root.
     -  We know we are in the leaf node when it has no children (children vector size is zero).
- **Role in the code:**
    - The function sets the height of each node in the tree.
- **Asymptotic Analysis:**
    - Assuming n be the number of nodes in the tree.

|  Time Complexity | O(n)  |
| ------------ | ------------ |
| **Space Complexity**  | **O(n)**  |

------------
<div id='ident-Function'/>



## **ident Function**

- **Role in the code:**
    - This function helps in XML pretty print which beautify/format the XML file and displays it in a tree view.
- **Parameters of the function:**
    -  String xml : This is a string holding the xml file desired to be prettified
- **Return type :**
    - String : This function return a string holding the prettified xml lines
- **How it works  :**
    - First , we initialize two variables , a string (res) to hold the resulted XML and a counter (cnt) to indicate the number of indents (white spaces)
    - Secondly, we loop through the whole passed string and check if have a closing tag or an opening tag or a tag value
    -  Counter is increased after we meet an opening tag and is decreased after we meet a closing tag
    - Then we add a new line at the end of each if-case
    - Lastly, return the resulted prettified XML.
- **Asymptotic analysis**:
    -  Assume the XML string size is n.

|   | Best case  |  Worst case |
| ------------ | ------------ | ------------ |
|  Time Complexity |  O(1) |  O(n) |
|  Space Complexity|  O(1) |  O(n) |
------------
<div id='same_childs-Function'/>

## **same_childs Function**

- **Parameters of the function:**
     - root (Node*): This is the parent node of the children nodes.
- **Return type:**
    -  bool: the function returns true if the children are all of the same type and returns false if the children are different.

- **How it works:**
    - The function takes the parent node as a parameter, access its childs vector which contains all the children of this node, we store the string of the first element and then iterate over the strings of the rest of elements and check if they are the same string, if so, then return true, else return false.
     -  There’s a case in which the parent has only one child, then we return false directly.
- **Role in the code:**
    - The function helps to make a decision whether we create a JSON list or just create an object.
- **Asymptotic Analysis:**
    - Assuming the parent node has n children, and average child’s string length of m


|  Time Complexity | O(n)  |
| ------------ | ------------ |
| **Space Complexity**  | **O(m)**  |
------------
<div id='conv_children-Function'/>


## **conv_children Function**
- **Parameters of the function:**
     - root (Node*): this is the root of the tree meant to be converted into JSON format
    - identCount (int): this parameter meant to control spacing in each line.
- **Return type:**
    -  string: the function returns a string with a whole formatted JSON code.
- **How it works:**
    - The function takes the root of the tree as a parameter and the level of indentation, each level in the tree must have incremented indentation level.
    - The function is recursive with a base case when the height of the root given is 1, then it returns the tag of the root wrapped in double quotes.
    -  f the height is more than 1, the function here has to know if it should make a list or object, so it calls same_childs function.
    -  If same_childs returned true, then we open a square brackets of the list, and the function iterates over the childs vector and calls itself again with identCount equals the original identCount parameter came to the function + 1 until reach the base case, the same happen if same_childs returned false, but instead of opening square brackets we open curly braces.
- **Role in the code:**
    - This function is meant to convert the tree structure of the original XML code and returns a formatted string of JSON format.
- **Asymptotic Analysis**:
    - Assuming the tree we iterate through has k nodes, and if the tree’s root has more than one child then it calls for each child the same_childs function of time complexities O(n) as previously explained, n is the number of children with the same parent.


|  Time Complexity | O(kn)  |
| ------------ | ------------ |
| **Space Complexity**  | **O(k^2)**  |
------------
<div id='tree_to_json-Function'/>

## **tree_to_json Function**

- **Parameters of the function:**
    -  root (Node*): this is the root of the tree that came from the structure of the xml original code.
     - type (json_type): this parameter is to specify whether to call conv_children with formatted JSON structure of conv_children_comp which is the compressed JSON string.
- **Return type:**
    -  string: return the string came from one of the two functions it controls.
- **How it works**:
     - The function takes the very first root of the tree and the type of operation to make and then call and return conv_children function if json_type is normal, or call and return conv_children_comp if json_type is compressed.
 - **Asymptotic Analysis** of this function in both space and time complexities are both O(1), as this function only controls which function to call.


------------

<div id='encode-Function'/>

## **encode Function**

- **Parameters of the function:**
    - xml: string – the xml you want to encode
- **Return:**
    - string: the encoded xml string
- **How it works:**
    -  First the function assumes that the input string has no white spaces between the tags, only the spaces between the leaf text nodes, this step is done in the input functions as part of the whole procedure.
    - The function iterates over all the string xml looking for opening or closing tags, then replacing these tags with predefined mapped ASCII characters that is impossible to exist in the file by normal.
    - eplacing these tags which usually has more than one character with only one mapped character reduces the size significantly.
- **Role in the code**
    -  This is part of the XML decoding-encoding procedures that our program supports.
- **Asymptotic Analysis:**
    - Let n be the length of the input string, then the running and space complexity are:

|  Time Complexity | O(n)  |
| ------------ | ------------ |
| **Space Complexity**  | **O(n)**  |

------------
<div id='decode-Function'/>


## **decode Function**

- **Parameters of the function:**
    - xml: string – the xml you want to decode
- **Return:**
    - string: the decoded xml string
- **How it works:**
 -    - The function iterates over the input string looking for the predefined ACSII mapped characters and replaces them with the correct mapped tag, leaving the other characters without change.
- **Role in the code**
     - This is part of the XML decoding-encoding procedures that our program supports.
- **Asymptotic Analysis:**
     - Let n be the length of the input string, then the running and space complexity are:

|  Time Complexity | O(n)  |
| ------------ | ------------ |
| **Space Complexity**  | **O(n)**  |


------------
<div id='conv_children_comp-Function'/>

## **conv_children_comp Function**
- **Parameters of the function:**
     -  root: Node* – pointer to the root of the json tree
- **Return:**
    -  string: the encoded json string
- **How it works:**
    -  This function is pretty much like “conv_children” except that it replaces the opening and closing tags with predefined mapped ASCII characters that is impossible to exist in the file by normal.
    -  The function operates in recursive way, with base case that the height of tree descend from the input Node pointer is 1 then this is leaf text Node that left unchanged.
    - First checking for the children’s of the input Node if they have the save tag, if so then this is JSON list, that has no parent tag text, then the function call itself again on each of its children’s.
    -  Finally, if the children’s have different tags, then it’s JSON object that need the parent tag text to be passed in the output JSON, but we replace that tag with its corresponding mapped ACSII character.
    - Replacing these tags which usually has more than one character with only one mapped character reduces the size significantly.
- **Role in the code**
    - This is part of the JSON decoding-encoding procedures that our program supports.
- **Asymptotic Analysis:**
    -  Let n be the number of nodes forming out JSON tree, and m is the average string length of the tags in the tree, then the running and space complexity are:

|  Time Complexity | O(nm)  |
| ------------ | ------------ |
| **Space Complexity**  | **O(nm)**  |

------------
<div id='decode_json-Function'/>


## **decode_json Function**

- **Parameters of the function**:
    - json: string – the json you want to decode
- **Return:**
    -  string: the decoded json string
- **How it works:**
    - The function iterates over the input string looking for the predefined ACSII mapped characters and replaces them with the correct mapped value, leaving the other characters without change.
- **Role in the code**
    - This is part of the JSON decoding-encoding procedures that our program supports.
- **Asymptotic Analysis:**
    -  Let n be the length of the input string, then the running and space complexity are:

|  Time Complexity | O(n)  |
| ------------ | ------------ |
| **Space Complexity**  | **O(n)**  |
------------
<div id='GUI-Layout'/>

## **GUI Layout**


![](https://i.postimg.cc/mgcF8R2f/Capture.jpg)

<div id='List-of-References'/>

## **List of References**
- Dr. Islam Ahmed Lectures
- Data Structure and Algorithm Analysis in C++ - Mark Allen Weiss 4th Edition
- GeeksforGeeks | A computer science portal for geeks
- Qt Creator Manual



<div id='End'/>



## **End**