using UnityEngine;

public class back : MonoBehaviour
{
    public GameObject helpObject;
    public GameObject title;
    public GameObject play;
    public GameObject helpB;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void OnClick()
    {

        helpObject.SetActive(false);
        title.SetActive(true);
        play.GetComponent<CanvasGroup>().alpha = 1f;
        helpB.SetActive(true);

    }
}
