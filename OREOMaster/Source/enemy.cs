using UnityEngine;

public class enemy : MonoBehaviour
{

    public GameObject enemyPrefab;
    private bool isReadyToLaunch = false;
    private Rigidbody2D rb;
    public float hitForce = 500f; // Force used to launch the enemy
    public float rotationForce = 300f; // Rotation force applied to the enemy
    public Sprite[] enemySprites;

    private SpriteRenderer sr;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        isReadyToLaunch = true;
        rb = GetComponent<Rigidbody2D>();
        rb.bodyType = RigidbodyType2D.Kinematic;
        sr = GetComponent<SpriteRenderer>();

        int randomIndex = Random.Range(0, enemySprites.Length); // Choose a random index
        sr.sprite = enemySprites[randomIndex];
    }

    // Update is called once per frame
    void Update()
    {
    }

   public void LaunchEnemy()
    {
        if (isReadyToLaunch) {
        isReadyToLaunch = false; // Once launched, it no longer responds to the Enter key
        // Disable Kinematic so the Rigidbody can be affected by physics
            rb.bodyType = RigidbodyType2D.Dynamic;
            Vector2 launchDirection = new Vector2(Random.Range(-1f, 1f), Random.Range(0.5f, 1.5f)).normalized;
        rb.AddForce(launchDirection * hitForce, ForceMode2D.Impulse); // Use ForceMode2D with AddForce
            float randomTorque = Random.Range(-1f, 1f) * rotationForce;
        rb.AddTorque(randomTorque, ForceMode2D.Impulse); // ForceMode2D.Impulse applies a one-time impulse

        // Decide whether to spawn a new enemy when this enemy is launched

            GenerateNewEnemy();
        // Destroy the launched enemy after a short delay whether or not a new enemy is spawned
        Destroy(gameObject, 2f); // Destroy the launched enemy after 2 seconds
        }
        
    }

    void GenerateNewEnemy()
    {
            // Spawn a new enemy at the current enemy position and rotation
        Vector3 spawnPosition = transform.position;
        spawnPosition.z += 0.1f;
        GameObject newEnemy = Instantiate(enemyPrefab, spawnPosition, transform.rotation);
        
    }

}

