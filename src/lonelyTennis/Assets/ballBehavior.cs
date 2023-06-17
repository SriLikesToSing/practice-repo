using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

/*
    - final things to add
        - ball having a comet trail**CHECK
        - ball double bounce detection**CHECK
        - simple menu**CHECK
        - skybox**CHECK
        - score system**CHECK
        - YOURE DONE WITH THE GAME **YAYAYAYAYYY
*/

public class ballBehavior : MonoBehaviour
{
    public GameObject ball;
    public Rigidbody Rb;
    public Transform aimTarget; 
    public Text textScore;
    public int counter = 0;
    public int score = 0;
    public float zSpeed = -7.0f;

    

    private void restartGame(){
        SceneManager.LoadScene("SampleScene");
        Debug.Log("GAME OVER BITCH COME OVER HERE AND SUCK MY DING DONG");

    }

    void Update(){
        if(ball.transform.position.y <= -20){
            restartGame();
        }
    } 

    private void OnCollisionEnter(Collision collision){
        if(collision.gameObject.tag == "wall"){
            Debug.Log("Score: ");
            Debug.Log(score);
            textScore.text = score.ToString();

            if(score%10 == 0 && score != 0){
                zSpeed-=(-1.0f);
            }

            Vector3 dir = aimTarget.position - transform.position;
            Rb = ball.GetComponent<Rigidbody>();
            Rb.velocity = dir.normalized * -2 + new Vector3(Random.Range(-3.0f, 3.0f), -2, Random.Range(zSpeed-2.0f, zSpeed));
        }

        if(collision.gameObject.tag == "platform"){
            counter+=1;
            if(counter == 2){
                restartGame();
            }
        }
    }

    private void OnTriggerEnter(Collider trigger){
        if(trigger.CompareTag("paddle")){
                Debug.Log("wall collision, sending poopoo right away");
        }
        counter = 0;
        score+=1;
    }
}
