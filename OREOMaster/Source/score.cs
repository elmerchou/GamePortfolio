using UnityEngine;
using UnityEngine.UI;


public class score : MonoBehaviour
{

    int currentscore;
    int scoreDisplayDigits = 8;
    public GameObject record;

    public Text scoreText;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        scoreText.text = "SCORE:00000000";
        currentscore = 0;
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    public void ScoreUpdate(int length,int combo,bool right)
    {
        int temp = Mathf.RoundToInt(length * 50 * (1 + combo * 0.1f) * (right ? 2:1));
        Debug.Log(temp);
        currentscore += temp*2;
        string formattedScore = currentscore.ToString("D" + scoreDisplayDigits);
        scoreText.text = "SCORE:" + formattedScore;
        record.GetComponent<scoreRecorder>().SetScore(currentscore);
    }
    public void ScoreCheater()
    {
        currentscore = 777;
        string formattedScore = currentscore.ToString("D" + scoreDisplayDigits);
        scoreText.text = "SCORE:" + formattedScore;
        record.GetComponent<scoreRecorder>().SetScore(777);
    }
}
