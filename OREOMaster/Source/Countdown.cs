using UnityEngine;
using UnityEngine.UI;


public class NewMonoBehaviourScript : MonoBehaviour
{
    public float totalTime = 60.9f; // Sets the total countdown time, default is 60 seconds
    public Text timerText;        // UI text element used to display the time

    private float currentTime;    // Current countdown time
    private int currentTimeI;    // Current countdown time as an integer

    public bool isStart;
    public GameObject eventSystem;

    void Start()
    {
        isStart = false;
        currentTime = totalTime; // Initialize the current countdown time with the total time
        //currentTimeI = (int)(currentTime);
    }

    void Update()
    {
        if (isStart)
        {
            // Decrease the time every frame
            currentTime -= Time.deltaTime;

            // Make sure the time does not go below zero
            if (currentTime <= 10) { 
                timerText.color = Color.red;
            }
            else
            {
                timerText.color = Color.black;
            }
            if (currentTime <= 0)
            {
                currentTime = 0;
                // Add logic for when the countdown ends here, for example:
                Debug.Log("Countdown finished!");
                // For example, disable this script to stop further updates
                eventSystem.GetComponent<Test>().GameOver();
                enabled = false;
            }
            else
            {
                currentTimeI = (int)(currentTime);

            }

            // Update the UI text display
            timerText.text = "TIME：" + currentTimeI;
            //Debug.Log(currentTimeI);
        }

    }

    //    void UpdateTimerDisplay()
    //    {
    //        // Format the time as minutes:seconds
    //        int minutes = Mathf.FloorToInt(currentTime / 60);
    //        int seconds = Mathf.FloorToInt(currentTime % 60);

    //        timerText.text = string.Format("{0:00}:{1:00}", minutes, seconds);
    //    }

    //    // You can also set a countdown start time from the Inspector
    //    public void SetStartTime(float time)
    //    {
    //        totalTime = time;
    //        currentTime = totalTime;
    //        enabled = true; // Re-enable the script if it was disabled
    //    }

    public void TurnOn()
    {
        isStart=true;
    } 
    public void Minus()
    {

    }

    public void Plus()
    {
        currentTime += 5.0f;
    }

    public void Zero()
    {
        currentTime =0.0f;
    }
}
