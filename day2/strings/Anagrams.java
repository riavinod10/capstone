import java.util.Arrays;

public class Anagrams {
    
    public boolean TwoStringAnagram(String s, String t){
        if(s.length() != t.length()) return false;
        
        char[] a = s.toCharArray();
        char[] b = t.toCharArray();
        Arrays.sort(a);
        Arrays.sort(b);
        return Arrays.equals(a,b);
    }
    
    public static void main(String[] args){
        Anagrams obj = new Anagrams();
        System.out.println(obj.TwoStringAnagram("listen","silent"));
        //System.out.println();
    }
}