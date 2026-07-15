using UnityEngine;
using UnityEngine.UI;
using System.Collections; // Required for IEnumerator


public class combo : MonoBehaviour
{
    public Text comboText;

    public int comboAmount;
    public string comboString;
    public float delay = 0.03f;


    public float floatAmplitude = 20f; // Floating amplitude (maximum vertical movement distance)
    float floatSpeed = 3f;      // Floating speed

    private RectTransform rectTransform; // Text RectTransform component
    private float startY;                // Initial Y position of the text

    public GameObject fire;
    private Animator animatedUIAudioAnimator;
    private CanvasGroup myCanvasGroup;

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {

        animatedUIAudioAnimator = fire.GetComponent<Animator>();
        comboAmount = 0;
        comboText.text = "";
        rectTransform = GetComponent<RectTransform>();
        startY = rectTransform.anchoredPosition.y;
        myCanvasGroup = fire.GetComponent<CanvasGroup>();
        myCanvasGroup.alpha = 0f;
    }

    // Update is called once per frame
    void Update()
    {
        float newY = startY + Mathf.Sin(Time.time * floatSpeed) * floatAmplitude;

        // Update the Y position of the RectTransform
        // Keep the X and Z axes unchanged
        rectTransform.anchoredPosition = new Vector2(rectTransform.anchoredPosition.x, newY);
    }

    IEnumerator ShowText()
    {
        myCanvasGroup.alpha = 0f;
        for (int i = 0; i < comboString.Length + 1; i++)
        {
            // Reveal the text one character at a time
            string currentText = comboString.Substring(0, i);

            // For legacy UI Text:
            comboText.text = currentText;
        

            // Wait before showing the next character
            yield return new WaitForSeconds(delay);
        }
        if (comboAmount < 5)
        {
            myCanvasGroup.alpha = 0f;
        }
        else if (comboAmount < 10)
        {
            myCanvasGroup.alpha = 1f;
            PlayAnimatedUINewAnimation("fire_blue");
        }else if(comboAmount < 15)
        {
            myCanvasGroup.alpha = 1f;
            PlayAnimatedUINewAnimation("fire_green");
        }
        else if (comboAmount < 20)
        {
            myCanvasGroup.alpha = 1f;
            PlayAnimatedUINewAnimation("fire_yellow");
        }
        else
        {
            myCanvasGroup.alpha = 1f;
            PlayAnimatedUINewAnimation("fire_red");
        }
    }
    IEnumerator BreakText()
    {
        myCanvasGroup.alpha = 0f;
        for (int i = 0; i < comboString.Length + 1; i++)
        {
            // Reveal the text one character at a time
            string currentText = comboString.Substring(0, comboString.Length-i);

            // For legacy UI Text:
            comboText.text = currentText;


            // Wait before showing the next character
            yield return new WaitForSeconds(delay);
        }
    }

    public void ComboUp()
    {
        comboAmount ++;
        if(comboAmount != 0)
        {
            if (comboAmount < 10) {
                comboString = "Combo：0" + comboAmount;
            }
            else
            {
                comboString = "Combo：" + comboAmount;
            }
               
            StopAllCoroutines(); // Stop any previously running coroutine
            StartCoroutine(ShowText()); // Start a new typing effect

        }
    }

    public void ComboReset()
    {
        
        //comboString = "Combo：" + comboAmount;
        StopAllCoroutines(); // Stop any previously running coroutine
        if(comboAmount!= 0)
        {
            StartCoroutine(BreakText()); // Start a new typing effect
        }
        
        comboAmount = 0;


    }
    public int GetCombo()
    {
        return comboAmount;


    }

    void PlayAnimatedUINewAnimation(string animationTriggerName)
    {
        animatedUIAudioAnimator.Play(animationTriggerName);

    }
}
