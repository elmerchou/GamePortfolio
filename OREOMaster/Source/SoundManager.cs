using UnityEngine;

public class SoundManager : MonoBehaviour
{
    public AudioSource audioSource; // Drag the AudioSource component here
    public AudioClip[] soundEffects; // Stores sound effect clips

    void Start()
    {
        // If AudioSource is not assigned in the Inspector, get it here
        if (audioSource == null)
        {
            audioSource = GetComponent<AudioSource>();
        }

        // Make sure the AudioSource exists
        if (audioSource == null)
        {
            Debug.LogError("AudioSource component not found. Please make sure this GameObject has an AudioSource.");
        }
    }

    // Play the sound effect at the specified index
    public void PlaySound(int soundIndex)
    {
        if (audioSource != null && soundEffects != null && soundIndex >= 0 && soundIndex < soundEffects.Length)
        {
            // Stop the AudioSource if it is already playing
            if (audioSource.isPlaying)
            {
                audioSource.Stop();
            }
            // Set the new audio clip
            audioSource.clip = soundEffects[soundIndex];
            // Play the new sound effect
            audioSource.Play();
        }
        else
        {
            Debug.LogWarning("Unable to play sound: invalid index or missing audio clip.");
        }
    }

    public void PlaySoundLoop(int soundIndex)
    {
        if (audioSource != null && soundEffects != null && soundIndex >= 0 && soundIndex < soundEffects.Length)
        {
            // Stop the AudioSource if it is already playing
            if (audioSource.isPlaying)
            {
                audioSource.Stop();
            }
            // Set the new audio clip
            audioSource.clip = soundEffects[soundIndex];
            // Play the new sound effect
            audioSource.Play();
            audioSource.loop = true;
        }
        else
        {
            Debug.LogWarning("Unable to play sound: invalid index or missing audio clip.");
        }
    }
    public void Stop()
    {
        
            // Stop the AudioSource if it is already playing
            if (audioSource.isPlaying)
            {
                audioSource.Stop();
            }
            
    }

}
