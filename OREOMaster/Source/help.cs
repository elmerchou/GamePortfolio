using UnityEngine;
using UnityEngine.EventSystems;

public class help : MonoBehaviour, IPointerEnterHandler
{

    public GameObject helpObject;
    public GameObject title;
    public GameObject play;
    public GameObject helpB;

    public SoundManager soundManager_oreo;
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

        helpObject.SetActive(true);
        title.SetActive(false);
        play.GetComponent<CanvasGroup>().alpha = 0f;
        helpB.SetActive(false);


    }

    public void OnPointerEnter(PointerEventData eventData)
    {
       
        soundManager_oreo.PlaySound(1);
       
    }
}
