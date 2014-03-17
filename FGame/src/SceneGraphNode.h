/*******************************************************************************
 * Authors:    Jesse Clary
 *             Landon Epps
 *             Andrew Kliphon
 *             Jeremy Stark
 * Assignment: MOE (Most Optimistic Engine)
 * Class:      4342, Spring 2014
 * Date:       3/16/2014
 *
 * Scene Graph data structure that handles simple transformations.
*******************************************************************************/

#ifndef SCENEGRAPHNODE_H_
#define SCENEGRAPHNODE_H_

#include "Mesh.h"

class SceneGraphNode
{
    public:
        SceneGraphNode(Mesh *mesh);
        virtual ~SceneGraphNode();

        void setTransformation(glm::mat4 matrix);
        glm::mat4 getTransformation();
        glm::mat4 getWorldTransformation();

        Mesh *getMesh();
        void setMesh(Mesh *mesh);

        void insertChild(SceneGraphNode *node);
        virtual void update();
        void draw();

    protected:
        SceneGraphNode *parent;
        Mesh *mesh;
        glm::mat4 transformation;
        glm::mat4 worldTransformation;
        vector<SceneGraphNode*> children;
};

#endif /* SCENEGRAPHNODE_H_ */
