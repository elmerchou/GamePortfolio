using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics.Contracts;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;
using UnityEngine.SceneManagement;

public class Test : MonoBehaviour
{


    //オブジェクトと結びつける
    public InputField myinputField;

    public string scene;

    public Transform canvasTransform; // Drag the Canvas here in the Inspector

    //public Text text;
    public GameObject o;
    public GameObject re;
    public GameObject player;
    public GameObject oreoGenerator;
    public GameObject object_timer;

    public Image blackUp;
    public Image blackDown;
    float moveDuration = 0.7f;
    private Vector3 startPosition_up;
    private Vector3 startPosition_down;


    public GameObject combo;
    public GameObject score;

    public SoundManager soundManager_oreo;
    public SoundManager soundManager_grade;

    public Text startText;

    public GameObject[] grade;

    public Animator _animator;
    float count = 0;
    int countOREO;
    int countOREOLast = 0;
    char[] enemyOREOnow;
    char[] myOREOnow;


    void Start()
    {
        myinputField.interactable = false;
        //Componentを扱えるようにする
        startPosition_up = blackUp.rectTransform.anchoredPosition;
        startPosition_down = blackDown.rectTransform.anchoredPosition;

        StartCoroutine(MoveOutBlackScreen());

       

    }

    void Update()
    {
        //if (Input.GetKeyDown(KeyCode.Return))
        //{


        //}

        if (Input.GetKeyDown(KeyCode.V) && (Input.GetKey(KeyCode.LeftControl) || Input.GetKey(KeyCode.RightControl))){

            object_timer.GetComponent<NewMonoBehaviourScript>().Zero();
            score.GetComponent<score>().ScoreCheater();
        }
    }

    void CheckField()
    {
        if (myinputField.text != "")
        {

            bool correct = true;
            char[] meOREO = myinputField.text.ToCharArray();
            for (int i = 0; i < meOREO.Length; i++)
            {
                meOREO[i] = char.ToLower(meOREO[i]);
            }



            List<char> filteredList = new List<char>();
            for (int i = 0; i < meOREO.Length; i++)
            {
                // 現在の文字が 'o' の場合
                if (meOREO[i] == 'o')
                {
                    filteredList.Add('o');
                }
                // 現在の文字が 'r' の場合、次の文字が 'e' であるかを確認
                else if (meOREO[i] == 'r')
                {
                    // 次の文字が存在し、かつそれが 'e' であるかを確認
                    if (i + 1 < meOREO.Length && meOREO[i + 1] == 'e')
                    {
                        filteredList.Add('r');
                        filteredList.Add('e');
                        i++; // 'e' も処理したので、インデックスをさらに1つ進める
                    }
                    else
                    {
                        correct = false;
                    }
                    // そうでない場合（'r' の次が 'e' でない、または配列の最後）、この 'r' は無視する
                }
                else
                {
                    correct=false;
                }
                // 'o' でも 'r' でもない他の文字は無視する
            }
            meOREO = filteredList.ToArray();
            string resultString = new string(meOREO);
            Debug.Log(resultString);

            if (meOREO.SequenceEqual(enemyOREOnow))
            {
                if (!correct)
                {
                    Debug.Log("MAMA");
                    soundManager_grade.PlaySound(1);
                    Canvas mainCanvas = FindFirstObjectByType<Canvas>();
                    canvasTransform = mainCanvas.transform;
                    Instantiate(grade[1], canvasTransform);
                    score.GetComponent<score>().ScoreUpdate(enemyOREOnow.Length, combo.GetComponent<combo>().GetCombo(),false);
                }
                else
                {
                    Debug.Log("YES");
                    soundManager_grade.PlaySound(0);
                    Canvas mainCanvas = FindFirstObjectByType<Canvas>();
                    canvasTransform = mainCanvas.transform;
                    Instantiate(grade[2], canvasTransform);
                    score.GetComponent<score>().ScoreUpdate(enemyOREOnow.Length, combo.GetComponent<combo>().GetCombo(),true);
                    
                }
                
                _animator.Play("yes");

                
                combo.GetComponent<combo>().ComboUp();
                if (combo.GetComponent<combo>().GetCombo() % 5 == 0)
                {
                    object_timer.GetComponent<NewMonoBehaviourScript>().Plus();
                }

                oreoGenerator.GetComponent<oreo_generator>().Generate(combo.GetComponent<combo>().GetCombo());
                GameObject[] allOreos = GameObject.FindGameObjectsWithTag("player_oreo");
                foreach (GameObject oreo in allOreos)
                {
                    // Get the target script from the object if needed
                    oreo.tag = "attacking";
                    oreo.GetComponent<oreo_attack>().AchieveCondition();
                }
                GameObject[] allEnemies = GameObject.FindGameObjectsWithTag("enemy");
                foreach (GameObject enemy in allEnemies)
                {
                    // Get the target script from the object if needed
                    enemy.GetComponent<enemy>().LaunchEnemy();
                }
            }
            else
            {
                combo.GetComponent<combo>().ComboReset();
                Debug.Log("Noway");
                soundManager_grade.PlaySound(2);
                Canvas mainCanvas = FindFirstObjectByType<Canvas>();
                canvasTransform = mainCanvas.transform;
                Instantiate(grade[0], canvasTransform);

                _animator.Play("down");

            }
        }

        myinputField.text = "";
        myinputField.Select();
        myinputField.ActivateInputField();

    }

    public void InputText()
    {
        countOREO = 0;
        count = 0.0f;
        //テキストにmyinputFieldの内容を反映
        //Debug.Log(myinputField.text);
        char[] splitStr = myinputField.text.ToCharArray();
        myOREOnow = splitStr;

        int finaloreo = 0;
        bool check = false;

        Array.Reverse(splitStr);
        GameObject[] players = GameObject.FindGameObjectsWithTag("player_oreo");

        // Iterate through the array and destroy each one
        foreach (GameObject player in players)  Destroy(player);
        for (int i = 0; i < splitStr.Length; i++)
        {

            if (Char.ToLower(splitStr[i]) == 'o')//0.26
            {

                // Cubeプレハブを元に、インスタンスを生成、
                count += 0.18f;
                Instantiate(o, new Vector3(-2.15f, -4.3f+count, 0.0f), Quaternion.identity);
                count+= 0.18f;
                
                countOREO++;
                if (!check)
                {
                    finaloreo = 0;
                    check = true;
                }
                

            }
            else if (i != splitStr.Length-1)
            {
                if (Char.ToLower(splitStr[i]) == 'e' && Char.ToLower(splitStr[i + 1]) == 'r')
                {
                    // Cubeプレハブを元に、インスタンスを生成、
                    count += 0.1f;
                    Instantiate(re, new Vector3(-2.15f, -4.3f + count, 0.0f), Quaternion.identity);
                    count += 0.1f;

                    countOREO++;
                    if (!check)
                    {
                        finaloreo = 1;
                        check = true;
                    }

                   
                }

            }

           
        }
        if (countOREO > countOREOLast)
        {
            _animator.Play("player");
            countOREOLast = countOREO;
            Debug.Log(countOREO);
            soundManager_oreo.PlaySound(finaloreo);
        }
        else if (countOREO < countOREOLast)
        {
            countOREOLast = countOREO;
        }

    }

    public void GetOREO(int[] status)
    {
        //string result3 = string.Join("", status);
        //Debug.Log(new string(result3));
        int count = 0;
        for (int i = 0; i < status.Length; ++i)
        {
            if (status[i] == 0)
            {
                count++;
            }
            else
            {
                count += 2;
            }
        }
        //Debug.Log(count);
        enemyOREOnow = new char[count];
        int charArrayIndex = 0;
        for (int i = 0; i < status.Length; ++i)
        {
            if (status[i] == 0)
            {
                enemyOREOnow[charArrayIndex] = 'o';
                charArrayIndex++; // Move to the next position in the char array
            }
            else // status[i] is not 0
            {
                enemyOREOnow[charArrayIndex] = 'r';
                charArrayIndex++; // Move to the next position
                enemyOREOnow[charArrayIndex] = 'e';
                charArrayIndex++; // Move to the next position
            }

        }


    }

    IEnumerator MoveOutBlackScreen()
    {
        float timer = 0f;
        Vector3 endPosition_up = startPosition_up; // Target position starts from the current position
        Vector3 endPosition_down = startPosition_down; // Target position starts from the current position
        endPosition_up = new Vector3(startPosition_up.x, 810f, startPosition_up.z);
        endPosition_down = new Vector3(startPosition_down.x, -810f, startPosition_down.z);

        soundManager_grade.PlaySound(3);

        while (timer < moveDuration)
        {
            timer += Time.deltaTime;
            // Smoothly move between the start and end positions with Lerp
            blackUp.rectTransform.anchoredPosition = Vector3.Lerp(startPosition_up, endPosition_up, timer / moveDuration);
            blackDown.rectTransform.anchoredPosition = Vector3.Lerp(startPosition_down, endPosition_down, timer / moveDuration);
            yield return null; // Wait for the next frame
        }

        

        // Ensure the final position is exact
        blackUp.rectTransform.anchoredPosition = endPosition_up;
        blackDown.rectTransform.anchoredPosition = endPosition_down;


        yield return new WaitForSeconds(0.5f);
        soundManager_grade.PlaySound(5);

        startText.text = "READY.";
        yield return new WaitForSeconds(0.7f);

        startText.text = "READY..";
        yield return new WaitForSeconds(0.7f);

        startText.text = "READY...";
        yield return new WaitForSeconds(0.7f);

        startText.text = "GO!!!";


       

        myinputField.interactable = true;


        object_timer.GetComponent<NewMonoBehaviourScript>().TurnOn();
        myinputField = myinputField.GetComponent<InputField>();
        myinputField.Select();

        myinputField.onEndEdit.AddListener(delegate { CheckField(); });

        yield return new WaitForSeconds(0.5f);

        startText.text = "";

    }

    public void GameOver()
    {
        StartCoroutine(MoveInBlackScreen());
    }

    IEnumerator MoveInBlackScreen()
    {
        myinputField.interactable = false;


        startText.text = "TIME OUT!";
        soundManager_grade.PlaySound(6);
        yield return new WaitForSeconds(1.5f);

        soundManager_grade.PlaySound(4);

        float timer = 0f;
        startPosition_up = blackUp.rectTransform.anchoredPosition;
        startPosition_down = blackDown.rectTransform.anchoredPosition;
        Vector3 endPosition_up = startPosition_up; // Target position starts from the current position
        Vector3 endPosition_down = startPosition_down; // Target position starts from the current position
        endPosition_up = new Vector3(startPosition_up.x, 270f, startPosition_up.z);
        endPosition_down = new Vector3(startPosition_down.x, -270f, startPosition_down.z);

        soundManager_grade.PlaySound(3);

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


}
