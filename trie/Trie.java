import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

/** Node implementing a Trie. Has a character and children.
    Boolean to indicate leaf node */
class TrieNode{
	char c;
	HashMap<Character,TrieNode> children = new HashMap<Character,TrieNode>();
	boolean isLeaf;

	public TrieNode(){

	}

	public TrieNode(char c){
		this.c = c;
	}
}

/** Class implementing Trie operations,
    Building a Trie, searching it, printing it, finding length of longest word
*/
class Trie{

TrieNode root;

public Trie(){
	root = new TrieNode();
}

public void insert(String word){
	HashMap<Character,TrieNode> children = root.children;

    for (int i=0;i<word.length();i++){
    	char c = word.charAt(i);
    	TrieNode currentNode;
    	if(children.containsKey(c)){
    		currentNode = children.get(c);
    		
    	}else{
    	 		currentNode= new TrieNode(c);
    	 		children.put(c,currentNode);
    	}
    	children = currentNode.children;
    	if(i == word.length() -1){
    		currentNode.isLeaf = true;
    	}
    }
}

public void printTrie(){
	HashMap<Character,TrieNode> map = root.children;
	int level = 1;
	for(Character c : map.keySet()){
		System.out.println(c);
		printChildren(map.get(c),level);
	}
}

public boolean searchTrie(String word){
	HashMap<Character,TrieNode> children = root.children;
	for(int i =0 ; i< word.length(); i++ ){
		char c = word.charAt(i);
		if(children.containsKey(c)){
			 TrieNode t = children.get(c);
			 if(t.isLeaf){
			 	return true;
			 }else{
			  children = t.children;
			}
		}else{
			return false;
		}
	}
	return false;
}

public void printChildren(TrieNode t,int level){
	if(t.isLeaf){
		return;
	}
	HashMap<Character,TrieNode> children = t.children;
	for(Map.Entry m : children.entrySet()){
		String repeated = new String(new char[level]).replace("\0", "\t"); 
		System.out.println(repeated + m.getKey());
		printChildren((TrieNode)m.getValue(),level +1);
	}
}

public int countChildren(TrieNode t, int max){
	if(t.isLeaf){
		return 1;
	}
	HashMap<Character,TrieNode> children = t.children;
	
	for(Map.Entry m : children.entrySet()){
		int localMax = 0;
		localMax += countChildren((TrieNode)m.getValue(),localMax) + 1;
		max = Math.max(localMax,max);
	}
	return max;
}

public int longestWord(){
	int max = 0;
	HashMap<Character,TrieNode> map = root.children;
	for(Character c : map.keySet()){
		max = Math.max(countChildren(map.get(c),max),max);
	}
	return max;	
}

public static void main(String args[]){
	Trie trie = new Trie();
	System.out.println("Enter the sentence: ");
	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	try{
	  String sentence = in.readLine();
	  String words[] = sentence.split(" ");
	  for (String word : words){
	  	trie.insert(word);
	  }
	 System.out.println("Entered sentence was: " + sentence);
	 trie.printTrie();

	 System.out.println("Enter the word to be searched: ");
	 in = new BufferedReader(new InputStreamReader(System.in));

     String searchWord = in.readLine();
     if(trie.searchTrie(searchWord)){
		System.out.println("Yes Word Exists!!");
	 }else{
		System.out.println("NO Tough luck!!");
     }

	System.out.println("Longest word length in the Trie: " + trie.longestWord());

    }
	catch(Exception e){
		System.out.println("Error in reading");
	}
 }

};