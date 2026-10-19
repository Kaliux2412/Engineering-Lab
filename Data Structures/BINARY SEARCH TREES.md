Definitions:
	BST Complexity: O(logn)
	When we have a line  which is the worst case escenario Complexity = O(n)

- Solo pueden tener 2 childs.
- Traversal: Operation that visits every node once.
- Binary Search Tree (BST): A tree where all values in the left subtree are smaller than the node and all the values in the right subtree are greater.
- ![[Pasted image 20261015101257.png]]
![[Pasted image 20261012093400.png]]
- Root = 43
- Leaf = like 12,68,16,82, etc.
- Parent = 25 is the parent of 23 and 37, so 23 and 37 are sibligns.
- Path: Sequence of edges, vertical, like 43-25-23-82
- Subtree: A node connected to everything below it 
- ![[Pasted image 20261012093807.png]]
- Depth: The length of the path from the root, like 58 has a depth of 2 (We start counting from 0)
- Degree: The number of childrens

Three orders:
![[Pasted image 20261015171108.png]]
- Preorder: ![[Pasted image 20261012095414.png]]
- Inorder:![[Pasted image 20261012095452.png]]
- Postorder: ![[Pasted image 20261012095552.png]]Primero se va con los arboles de la izquierda termina y se va con los de la izquierza hasta que llega al siguiente nivel, entonces se salta y se va al arbol derecho iniciando por la izquierda.
- ![[Captura de pantalla 2026-10-18 124604.png]]
- ![[Pasted image 20261015183950.png]]
Depth y Height:
- Depth: is the legth of the path from the root to a node. The root is at depth 0, its children at depth 1 and so on.
-  Height: The length of the longest path from a node down to a leaf. An empty tree has height -1. The height of the tree is the height of its root.
- ![[Pasted image 20261018125839.png|300]]
- ![[Pasted image 20261018125917.png|309]]
- ![[Pasted image 20261018125222.png|411]]![[Pasted image 20261018125209.png]]

Searching and Insertion:
- For this we compare and when you find a big value you search for the child.![[Pasted image 20261012101906.png]]![[Pasted image 20261012102001.png]]
- Insert: first search for values less than the one you want to insert, so when found we insert it in null.![[Pasted image 20261012102109.png]]![[Pasted image 20261012102205.png]]
- LevelOrder:![[Pasted image 20261018192331.png]]
- Deletion: Has 3 cases
	- Removing a leaf is easy because you don't have something below.
	- One child remove, we change the leaffor the child.![[Pasted image 20261012102615.png]]
	- Two children remove
	![[Pasted image 20261018192357.png]]
AVL Trees: 
	Para una left rotation el child se mueve hacia arriba por la derecha y el padre se baja a la izquierda, el root esta mas cargado a la derecha
	![[LeftRotatiom.excalidraw]]
	Para right rotation, esta mas cargado el lado izquierdo.
	![[RightRotationexcalidraw]]
- There are 4 cases:
	- Right-right:
	 ![[Pasted image 20261015092617.png|152]]
	-  Right-Left:
	- ![[Pasted image 20261015092734.png|163]]
	- Left-left:
	- ![[Pasted image 20261015094034.png|164]]
	- Left-Right:
	- ![[Pasted image 20261015094117.png|163]]
	- ![[Pasted image 20261015094313.png]]

- SPLAY:
	- Zag que quede el hijo a  derecha rotacion a la izquierda
	- Zig que quede el hijo a  la izquierda, rotacion a la derecha
	- Existen Zag-Zig, Zig-Zig, Zag-Zag, Zig-Zag, tmb
	- ![[Pasted image 20261018201210.png]]
	- Siempre se hace rotacion primero en el abuelo y luego en el padre