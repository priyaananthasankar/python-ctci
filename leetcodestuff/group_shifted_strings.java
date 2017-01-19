import java.util.ArrayList;
import java.util.List;
import java.util.HashMap;
import java.util.*;

class Grouper {

  List<List<String>> group  = new ArrayList<List<String>>();
  String[] strings;
  public Grouper(String strings[]){
  	this.strings = strings;
  }

  public void printGroup(List<List<String>> group){

  		for(List<String> arrList : group){
  			
  			System.out.println("[");
  			for(String str: arrList){
  				System.out.println(str);
  			}
  			System.out.println("]");
  		}
  	
  }

  public void groupStrings() {
    HashMap<Integer,List<List<String>>> groups = new HashMap<Integer,List<List<String>>>();

    for(String str : strings){
    	if(groups.containsKey(str.length())){

    		List<List<String>> listPerLength = groups.get(str.length());
    		boolean groupFound = false;
    		for(List<String> arrList: listPerLength){

    			    // take the first string only as they all are considered grouped into 1 list
    			    for(String currentStr : arrList){

    				int sampleLength = currentStr.charAt(0) - str.charAt(0);
    				if(sampleLength < 0 ){
    					sampleLength += 26;
    				}
    				boolean isGroupFound = true;
    				for(int i=0;i<currentStr.length();i++){
    					int diff = currentStr.charAt(i) - str.charAt(i);
    					if(diff < 0){
    						diff += 26;
    					}
    					if(diff != sampleLength){
    						isGroupFound = false;
    						break;
    					}
    				}
    				if(isGroupFound){
    					arrList.add(str);
    					groupFound = true;
    					break;
    				}
    			}
    		}
    		if(!groupFound){
    			ArrayList<String> newList = new ArrayList<String>();
    			newList.add(str);
    			listPerLength.add(newList);
    		}
    	}else{
    		List<List<String>> listPerLength = new ArrayList<List<String>>();
			List<String> strList = new ArrayList<String>();
			strList.add(str);
			listPerLength.add(strList);    		
    		groups.put(str.length(),listPerLength);
    	}
    }

    for(Integer length : groups.keySet()){
  		List<List<String>> val = groups.get(length);
  		for(List<String> arrList : val){
  			this.group.add(arrList);
  		}
  	}
    printGroup(group);
  }

  public static void main(String args[]){

   String strings[] = {"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z","mno","rtw"};
   Grouper grouper  = new Grouper(strings);
   grouper.groupStrings();
   
  }
 
}