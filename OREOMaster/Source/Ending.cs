using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using UnityEngine.SceneManagement;
using System;
using Unity.VisualScripting.FullSerializer;

public class Ending : MonoBehaviour
{

    public GameObject record;

    public Image blackUp;
    public Image blackDown;
    float moveDuration = 0.5f;


    public String scene;

    public float floatAmplitude = 20f; // Floating amplitude
    float floatSpeed = 2f;      // Floating speed

    private Vector3 startPosition_up;
    private Vector3 startPosition_down;

    public Image left;
    public Image right;
    private RectTransform rectTransform_left; // Left RectTransform component
    private RectTransform rectTransform_right; // Right RectTransform component
    private float startY_left;                // Initial Y position of the left object
    private float startY_right;                // Initial Y position of the right object

    public Text scoreText;
    public Text scoreText_2;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {

        

        record = GameObject.FindGameObjectsWithTag("record")[0];
        int score = record.GetComponent<scoreRecorder>().GetScore();

        scoreText.text = "SCORE:" + formattedScore;
        scoreText.text = "SCORE：" + formattedScore;

        if(score >= 150000)
        {
            scoreText_2.text = "OREO GOD!!!";
        }
        else if (score >= 110000)
        {
            scoreText_2.text = "OREO LORD!!";
        }
        else if(score >= 70000)
        {
            scoreText_2.text = "OREO MASER!!";
        }
        else if (score >= 30000)
        {
            scoreText_2.text = "OREO FRESHMAN!";
        }
        else if (score == 777)
        {
            scoreText_2.text = "OREO CHEATER!";
        }
        else 
        {
            scoreText_2.text = "OREO ROOKIE!";
        }




        startPosition_up = blackUp.rectTransform.anchoredPosition;
        startPosition_down = blackDown.rectTransform.anchoredPosition;


        rectTransform_left = left.GetComponent<RectTransform>();
        rectTransform_right = right.GetComponent<RectTransform>();
        startY_right = rectTransform_right.anchoredPosition.y;
        startY_left = rectTransform_left.anchoredPosition.y;

        StartCoroutine(MoveOutBlackScreen());
    }

    // Update is called once per frame
    void Update()
    {
        float newY_left = startY_left + Mathf.Sin(Time.time * floatSpeed) * floatAmplitude;
        float newY_right = startY_right + Mathf.Sin(Time.time * floatSpeed) * floatAmplitude;

        // Update the Y position of the RectTransform
        // Keep the X and Z axes unchanged
        rectTransform_left.anchoredPosition = new Vector2(rectTransform_left.anchoredPosition.x, newY_left);
        rectTransform_right.anchoredPosition = new Vector2(rectTransform_right.anchoredPosition.x, newY_right);
    }

    IEnumerator MoveOutBlackScreen()
    {
        float timer = 0f;
        Vector3 endPosition_up = startPosition_up; // Target position starts from the current position
        Vector3 endPosition_down = startPosition_down; // Target position starts from the current position
        endPosition_up = new Vector3(startPosition_up.x, 810f, startPosition_up.z);
        endPosition_down = new Vector3(startPosition_down.x, -810f, startPosition_down.z);

        //soundManager_grade.PlaySound(3);

        while (timer < moveDuration)
        {
            timer += Time.deltaTime;
            // Smoothly move between the start and end positions with Lerp
            blackUp.rectTransform.anchoredPosition = Vector3.Lerp(startPosition_up, endPosition_up, timer / moveDuration);
            blackDown.rectTransform.anchoredPosition = Vector3.Lerp(startPosition_down, endPosition_down, timer / moveDuration);
            yield return null; // Wait for the next frame
        }

        //soundManager_grade.PlaySound(5);

        // Ensure the final position is exact
        blackUp.rectTransform.anchoredPosition = endPosition_up;
        blackDown.rectTransform.anchoredPosition = endPosition_down;


        

    }

    public void OnClick()
    {
        Debug.Log("start");
        StartCoroutine(MoveInBlackScreen());
    }


    IEnumerator MoveInBlackScreen()
    {



        //soundManager_grade.PlaySound(4);

        float timer = 0f;
        startPosition_up = blackUp.rectTransform.anchoredPosition;
        startPosition_down = blackDown.rectTransform.anchoredPosition;
        Vector3 endPosition_up = startPosition_up; // Target position starts from the current position
        Vector3 endPosition_down = startPosition_down; // Target position starts from the current position
        endPosition_up = new Vector3(startPosition_up.x, 270f, startPosition_up.z);
        endPosition_down = new Vector3(startPosition_down.x, -270f, startPosition_down.z);

        //soundManager_grade.PlaySound(3);

        while (timer < moveDuration)
        {
            timer += Time.deltaTime;
            // Smoothly move between the start and end positions with Lerp
            blackUp.rectTransform.anchoredPosition = Vector3.Lerp(startPosition_up, endPosition_up, timer / moveDuration);
            blackDown.rectTransform.anchoredPosition = Vector3.Lerp(startPosition_down, endPosition_down, timer / moveDuration);
            yield return null; // Wait for the next frame
        }
        yield return new WaitForSeconds(1f);
        SceneManager.MoveGameObjectToScene(record, SceneManager.GetActiveScene());
        SceneManager.LoadScene(scene);


    }


}
