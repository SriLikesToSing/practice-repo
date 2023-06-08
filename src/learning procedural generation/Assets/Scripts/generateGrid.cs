using UnityEngine;
using System.Collections.Generic;
using System.Collections;

public class generateGrid : MonoBehaviour
{
    public GameObject blockGameObject;

    public GameObject objectToSpawn;

    public GameObject player;

    private int worldSizeX = 40;
    private int worldSizeZ = 40;

    private int noiseHeight = 5;

    //distance between each cube.
    private float gridOffset = 1.1f;

    private Vector3 startPosition;

    private Hashtable blockContainer = new Hashtable();

    private List<Vector3> blockPositions = new List<Vector3>();

    void Start()
    {
        for(int x=-worldSizeX;x<worldSizeX;x++){
            for(int z=-worldSizeZ; z<worldSizeZ;z++){
                Vector3 pos = new Vector3(x + startPosition.x, generateNoise(x,z,10f)*noiseHeight, z*1 + startPosition.z);
                //instantiate the cube with the newfound position and the rotation of the object
                GameObject block = Instantiate(blockGameObject, pos, Quaternion.identity) as GameObject;

                blockContainer.Add(pos, block);
                blockPositions.Add(block.transform.position);
                //sets transform to cube?? not sure.
                block.transform.SetParent(this.transform);
            }
        }

        //spawnObject();

    }

    void Update(){
        Debug.Log(xPlayerMove);
        Debug.Log(":");
        Debug.Log(zPlayerMove);

            for(int x=-worldSizeX;x<worldSizeX;x++){
                for(int z=-worldSizeZ; z<worldSizeZ;z++){
                    Vector3 pos = new Vector3(x + xPlayerLocation, generateNoise(x+xPlayerLocation,z+zPlayerLocation,10f)*noiseHeight, z*1 + zPlayerLocation);
                    
                    if(!blockContainer.ContainsKey(pos)){
                        //instantiate the cube with the newfound position and the rotation of the object
                        GameObject block = Instantiate(blockGameObject, pos, Quaternion.identity) as GameObject;

                        blockContainer.Add(pos, block);
                        blockPositions.Add(block.transform.position);
                        //sets transform to cube?? not sure.
                        block.transform.SetParent(this.transform);
                    }

                }
           }
    }

    public Vector3 getPlayerPosition{
        get{
            return (player.transform.position);
        }
    }

    public int xPlayerMove{
        get{
            return (int)(player.transform.position.x - startPosition.x);
        }
    }

    public int zPlayerMove{
        get{
            return (int)(player.transform.position.z - startPosition.z);
        }
    }

    private void spawnObject(){
        for(int c=0; c<20; c++){
            GameObject toPlaceObjet = Instantiate(objectToSpawn, objectSpawnLocation(), Quaternion.identity);
        }
    }

    private int xPlayerLocation{
        get{
            return (int)Mathf.Floor(player.transform.position.x);
        }

    }

    private int zPlayerLocation{
        get{
            return (int)Mathf.Floor(player.transform.position.z);
        }

    }

    private Vector3 objectSpawnLocation(){
        int rndIndex = Random.Range(0, blockPositions.Count);

        Vector3 newPos = new Vector3(
            blockPositions[rndIndex].x,
            blockPositions[rndIndex].y + 0.5f,
            blockPositions[rndIndex].z
        );

        blockPositions.RemoveAt(rndIndex);

        return newPos;
    }

    private float generateNoise(int x, int z, float detailScale){
        float xNoise = (x+this.transform.position.x) / detailScale;
        float zNoise = (z+this.transform.position.y) / detailScale;
        //perlin noise function has to take in atleast one float. If it has two integers then it will return same output
        return Mathf.PerlinNoise(xNoise, zNoise);


    }

}
