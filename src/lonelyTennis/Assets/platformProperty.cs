using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;


public class platformProperty : MonoBehaviour
{
    public static int counter = 0;
    private void OnCollisionEnter(Collision collision){
        if(collision.gameObject.tag == "ball"){
            //if certain amount of time has passed 
            if(counter == 2){
                SceneManager.LoadScene("SampleScene");
                Debug.Log("GAME OVER BITCH COME OVER HERE AND SUCK MY DING DONG");
            }
            Debug.Log("HELLO IT HAS HIT THE FLOOR!");
       }
    }
}
