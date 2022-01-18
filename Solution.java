
import java.util.Map;
import java.util.HashMap;

public class Solution {

    public boolean wordPattern(String pattern, String words) {

        Map<String, Integer> mapIndex = new HashMap();
        String[] arrayWords = words.split(" ");
        if (arrayWords.length != pattern.length()) {
            return false;
        }

        int size = pattern.length();
        for (int i = 0; i < size; i++) {

            String charID = "_" + pattern.charAt(i);
            mapIndex.putIfAbsent(charID, i);
            mapIndex.putIfAbsent(arrayWords[i], i);

            if (!mapIndex.get(charID).equals(mapIndex.get(arrayWords[i]))) {
                return false;
            }
        }
        return true;
    }
}
