using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using UnityEngine.SceneManagement;
using System;
using Unity.VisualScripting;
using System.Threading.Tasks.Sources;
using UnityEngine.EventSystems;


public class title : MonoBehaviour, IPointerEnterHandler
{
    public Image blackUp;
    public Image blackDown;
    float moveDuration = 0.5f;
    float moveDuration_title = 1f;
    




    public String scene;

    private Vector3 startPosition_up;
    private Vector3 startPosition_down;

    public float floatAmplitude = 20f; // Floating amplitude (maximum vertical movement distance)
    float floatSpeed = 2f;      // Floating speed


    public Image left;
    public Image right;
    private RectTransform rectTransform_left; // Left text RectTransform component
    private RectTransform rectTransform_right; // Right text RectTransform component
    private float startY_left;                // Initial Y position of the left text
    private float startY_right;                // Initial Y position of the right text


    public SoundManager soundManager_oreo;
    public SoundManager soundManager_grade;
    public SoundManager soundManager_BGM;


    float titleY = 267f;
    float playY = -92.95f;
    float helpY = -246f;
    public Button playButton;
    public Button helpButton;
    public Image titleImage;
    private RectTransform playTransform;
    private RectTransform helpTransform;
    private RectTransform titleTransform;


    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        
        startPosition_up = blackUp.rectTransform.anchoredPosition;
        startPosition_down = blackDown.rectTransform.anchoredPosition;
        rectTransform_left = left.GetComponent<RectTransform>();
        rectTransform_right = right.GetComponent<RectTransform>();
        startY_right = rectTransform_right.anchoredPosition.y;
        startY_left = rectTransform_left.anchoredPosition.y;

        playTransform = playButton.GetComponent<RectTransform>();
        helpTransform = helpButton.GetComponent<RectTransform>();
       titleTransform = titleImage.GetComponent<RectTransform>();
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

    public void OnClick()
    {

            Debug.Log("start");
            StartCoroutine(MoveInBlackScreen());

        
    }

    IEnumerator MoveInBlackScreen()
    {
        soundManager_BGM.Stop();


        soundManager_grade.PlaySound(1);

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
        SceneManager.LoadScene(scene);


    }

    IEnumerator MoveOutBlackScreen()
    {
        yield return new WaitForSeconds(0.5f);
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

        yield return new WaitForSeconds(0.5f);


        soundManager_grade.PlaySound(0);

        yield return new WaitForSeconds(1f);
        timer = 0f;
        Vector2 initialPosition_play = playTransform.anchoredPosition;
        Vector2 endPosition_play = new Vector2(initialPosition_play.x,playY);
        Vector2 initialPosition_help = helpTransform.anchoredPosition;
        Vector2 endPosition_help = new Vector2(initialPosition_help.x, helpY);
        Vector2 initialPosition_title = titleTransform.anchoredPosition;
        Vector2 endPosition_title = new Vector2(initialPosition_title.x, titleY);



        while (timer < moveDuration_title)
        {
            timer += Time.deltaTime;
            // Smoothly move between the start and end positions with Lerp
            playButton.GetComponent<RectTransform>().anchoredPosition = Vector2.Lerp(initialPosition_play, endPosition_play, timer / moveDuration_title);
            helpButton.GetComponent<RectTransform>().anchoredPosition = Vector2.Lerp(initialPosition_help, endPosition_help, timer / moveDuration_title);
            titleImage.GetComponent<RectTransform>().anchoredPosition = Vector2.Lerp(initialPosition_title, endPosition_title, timer / moveDuration_title);
            yield return null; // Wait for the next frame
        }
        playButton.GetComponent<RectTransform>().anchoredPosition = endPosition_play;
        helpButton.GetComponent<RectTransform>().anchoredPosition = endPosition_help;
        titleImage.GetComponent<RectTransform>().anchoredPosition = endPosition_title;

        soundManager_BGM.PlaySound(0);

    }

    public void OnPointerEnter(PointerEventData eventData)
    {
        GameObject enteredGameObject = this.gameObject;
        string objectName = enteredGameObject.name;
        if(objectName == "play")
        {
            soundManager_oreo.PlaySound(0);
        }else 
        {
            
            soundManager_oreo.PlaySound(1);
        }
    }


}
