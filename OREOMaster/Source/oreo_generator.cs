using UnityEngine;

public class oreo_generator : MonoBehaviour
{


    public GameObject o;
    public GameObject re;
    public GameObject manager;
    public Sprite[] dialog;
    private SpriteRenderer sr;
    int count;
    int[] status;
    float y= 0.0f;

    private Vector3 startPosition; // Stores the initial world position of the GameObject
    float floatSpeed = 2f;    // Floating speed, adjustable in the Inspector
    float floatAmplitude = 0.1f; // Floating amplitude, adjustable in the Inspector
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        sr = GetComponent<SpriteRenderer>();
        Generate(0);

        startPosition = transform.position;
    }
    // Update is called once per frame
    void Update()
    {
        float newY = startPosition.y + Mathf.Sin(Time.time * floatSpeed) * floatAmplitude;

        // Update the world position of the GameObject
        // Keep the X and Z axes unchanged
        transform.position = new Vector3(startPosition.x, newY, startPosition.z);
    }

    public void Generate(int combo)
    {
        GameObject[] objectsToDelete = GameObject.FindGameObjectsWithTag("oreo_enemy");

        // Iterate through these objects and destroy them
        foreach (GameObject obj in objectsToDelete)
        {
            Destroy(obj); // Destroy() removes the GameObject
        }
        y = 0.0f;
        if (combo < 5)
        {
            count = Random.Range(1, 4);
        }
        else if (combo < 10) {
            count = Random.Range(2, 6);
        }
        else if (combo < 15) {
            count = Random.Range(3, 8);
        }
        else
        {
            count = Random.Range(4, 10);
        }


        if (count <= 3)
        {
            sr.sprite = dialog[0];
        }
        else if (count <= 5)
        {
            sr.sprite = dialog[1];
        }
        else if (count <= 7)
        {
            sr.sprite = dialog[2];
        }
        else if (count <= 9)
        {
            sr.sprite = dialog[3];
        }
        status = new int[count];
        for (int i = 0; i < count; ++i)
        {
            status[i] = Random.Range(0, 2);
            if (status[i] == 0)
            {
                y += 0.225f;
            }
            else
            {
                y += 0.160f;
            }
        }
        y = 2.64f + y / 2;




        for (int i = 0; i < count; ++i)
        {

            if (status[i] == 0)
            {
                y -= 0.113f;
                Instantiate(o, new Vector3(1.75f, y, -4.0f), Quaternion.identity);
                y -= 0.113f;
            }
            else
            {
                y -= 0.085f;
                Instantiate(re, new Vector3(1.75f, y, -4.0f), Quaternion.identity);
                y -= 0.085f;
            }
        }

        manager.GetComponent<Test>().GetOREO(status);
    }
}
