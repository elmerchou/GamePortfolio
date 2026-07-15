using UnityEngine;

public class scoreRecorder : MonoBehaviour
{

    int score;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        DontDestroyOnLoad(gameObject);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    public void SetScore(int score_new)
    {
        score = score_new;
    }

    public int GetScore()
    {
        return score;
    }
    //public void DestroyThis()
    //{
    //    Destroy(this);
    //}
}
