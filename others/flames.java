import java.util.ArrayList;
import java.util.Arrays;

class flames {
    public static void main(String[] atrgs) {
        String s1 = "haricharan";
        String s2 = "gayathri";
        String shortest = s1.length() < s2.length() ? s1 : s2;
        String longest = s1.length() >= s2.length() ? s1 : s2;
        for(int i = 0 ; i < shortest.length(); i++) {
            int index = longest.indexOf(shortest.charAt(i)); 
            if( index > -1) {
                shortest = shortest.substring(0, i) + shortest.substring(i+1);
                longest = longest.substring(0, index) + longest.substring(index+1);
                i--;
            }
        }

        int length = shortest.length() + longest.length();
        ArrayList<Character> flames = (ArrayList)Arrays.asList(new Character[]{'F', 'L', 'A', 'M', 'E', 'S'});
        int index = 0;
        while (flames.size() > 1) {
            
        }
    }
}