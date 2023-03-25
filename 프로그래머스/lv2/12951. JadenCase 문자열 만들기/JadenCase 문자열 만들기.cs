// ToString() 메소드, ToUpper() 메소드 활용
// 삼항연산자
public class Solution {
    public string solution(string s) {
        string answer = "";
        
        answer = s[0].ToString().ToUpper();
        
        for(int i = 1; i < s.Length; i++)
        {
            answer += s[i-1] == ' ' ? s[i].ToString().ToUpper() : s[i].ToString().ToLower(); 
        }
        
        return answer;
    }
}