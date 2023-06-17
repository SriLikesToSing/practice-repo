//using System.Collections;
//using System.Collections.Generic;

/*
- I want to enable the rigid body so the ping pong paddle also has physics
    along with the ping pong ball**CHECK
- I want the paddle's y axis rotation to be constant and unaffected by gravity*CHECK
- The ball should not go above a certain height and speed 
*/


using UnityEngine;

public class dragObject : MonoBehaviour
{
    private Vector3 mOffset;

    private float mZCoord;
    
    private float mYCoord;

    private Vector3 prevMousePos;


    void OnMouseDown(){
        mZCoord = Camera.main.WorldToScreenPoint(gameObject.transform.position).z;
        mYCoord = Camera.main.WorldToScreenPoint(gameObject.transform.position).y;
        mOffset = gameObject.transform.position - getMouseWorldPos();
        prevMousePos = getMouseWorldPos();
    }

    private Vector3 getMouseWorldPos(){
        Vector3 mousePoint = Input.mousePosition;

//             mousePoint.z += ;//+= (mousePoint.y - prevMousePos.y);

        return Camera.main.ScreenToWorldPoint(mousePoint);
    }

    void OnMouseDrag(){
        transform.position = getMouseWorldPos() + mOffset;
    }
}
