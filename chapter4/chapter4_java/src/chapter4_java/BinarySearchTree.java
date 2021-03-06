package chapter4_java;

class Node{
	int data;
	Node left = null;
	Node right = null;
	
	public Node(int d){
		data = d;
	}
	
	public int getData(){
		return data;
	}
	
	public Node getLeft(){
		return left;
	}
	
	public Node getRight(){
		return right;
	}
	
	public void setLeft(Node n){
		left = n;
	}
	
	public void setRight(Node n){
		right = n;
	}
}

public class BinarySearchTree {
	Node root;
	public BinarySearchTree(){
		root = null;
	}
	
	public Node insertIntoTree(Node temp,Node newnode){
		if(temp == null){
			return newnode;
		}else if(newnode.data < temp.data){
			temp.setLeft(insertIntoTree(temp.getLeft(),newnode));
		}else if(newnode.data > temp.data){
			temp.setRight(insertIntoTree(temp.getRight(),newnode));
		}
		return temp;
	}
	
	public void displayTree(Node temp){
		if(temp == null){
			return;
		}else{
			displayTree(temp.getLeft());
			System.out.println(" " + temp.data);
			displayTree(temp.getRight());
		}
	}
	
	public void display(){
		displayTree(root);
	}
	
	public void insert(int data){
		root = insertIntoTree(root,new Node(data));
	}
	
	public static void main(String arg[]){
		BinarySearchTree b = new BinarySearchTree();
		b.insert(3);b.insert(8);
		b.insert(1);b.insert(4);b.insert(6);b.insert(2);b.insert(10);b.insert(9);
		b.insert(20);b.insert(25);b.insert(15);b.insert(16);
		System.out.println("Original Tree : ");
		b.display();	
		System.out.println("New Tree : ");
		b.insert(89000);
		b.display();	

		
	}
}
