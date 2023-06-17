// tilt paddle when going right and left? **CHECK
// collision system needs to be fixed
    /*
        when the paddle detects a collision with the ball it will pick a path and 
            it will not go above a certain height** not sutre about that
            
            - we don't need to hit the ball the paddle will "hit" the ball on its own so it 
                is more fluid

            - when ball hits the wall it will create custom trajectory such that it will only bounce once**CHECK
    */

using UnityEngine;

public class mousePosition3D : MonoBehaviour
{
    public GameObject ball;
    public Rigidbody Rb;

    public Transform aimTarget; 
    float speed = 3f;
    float force = 13;

    void Update(){
        Plane plane = new Plane(Vector3.up, new Vector3(0, 1, 0));
        Ray ray=Camera.main.ScreenPointToRay(Input.mousePosition);
        float distance;

        if(plane.Raycast(ray, out distance)){
            transform.position=ray.GetPoint(distance);
        }

        if(Input.GetMouseButtonDown(0)){
            transform.Rotate(new Vector3(0f, -60f, 0f));
        }
        
        if(Input.GetMouseButtonDown(1)){
            transform.Rotate(new Vector3(0f, 60f, 0f));
        }
    }

    private void OnTriggerEnter(Collider trigger){
        /*the velocity will always be constant and change the ball randomly and send it in a random direction 
        in close bounds to its current direction
        */
        if(trigger.CompareTag("ball")){
            //change direction randomly
                Vector3 dir = aimTarget.position - transform.position;
                trigger.GetComponent<Rigidbody>().velocity = dir.normalized * 3 + new Vector3(dir.x, 3, 10);
                Debug.Log("collision detected, sending bombs right away");
        }
    }

}
