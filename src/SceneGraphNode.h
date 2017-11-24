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
        /***********************************************************************
         * SceneGraphNode: Constructor.
        ***********************************************************************/
        SceneGraphNode();

        /***********************************************************************
         * SceneGraphNode: Constructor.
         *
         * mesh:      The mesh to be drawn.
        ***********************************************************************/
        SceneGraphNode(Mesh *mesh);

        /***********************************************************************
         * SceneGraphNode: Destructor.
        ***********************************************************************/
        virtual ~SceneGraphNode();



        /***********************************************************************
         * setTransformation: Sets this node's transformation matrix.
         *
         * matrix:    The transformation matrix to be applied.
         *
         * return:    void
        ***********************************************************************/
        void setTransformation(glm::mat4 matrix);

        /***********************************************************************
         * getTransformation: Returns this node's transformation matrix.
         *
         * return:    mat4
        ***********************************************************************/
        glm::mat4 getTransformation();

        /***********************************************************************
         * getWorldTransformation: Returns this node's world transformation
         *            matrix.
         *
         * return:    mat4
        ***********************************************************************/
        glm::mat4 getWorldTransformation();

        /***********************************************************************
         * getMesh:   Returns a pointer to this node's mesh.
         *
         * return:    Mesh pointer
        ***********************************************************************/
        Mesh *getMesh();

        /***********************************************************************
         * setMesh:   Sets this node's mesh.
         *
         * mesh:      The mesh to be drawn.
         *
         * return:    void
        ***********************************************************************/
        void setMesh(Mesh *mesh);



        /***********************************************************************
         * addChild:  Adds a child node to this parent (if no parent, then
         *            parent will be NULL).
         *
         * node:      The child node.
         *
         * return:    void
        ***********************************************************************/
        void addChild(SceneGraphNode *node);

        /***********************************************************************
         * update:    Updates all nodes applying parent transformations to child
         *            nodes.
         *
         * return:    void
        ***********************************************************************/
        virtual void update();

        /***********************************************************************
         * draw:      Draws all meshs in the scene graph.
         *
         * return:    void
        ***********************************************************************/
        void draw();

    protected:
        /** This node's parent. **/
        SceneGraphNode *parent;
        /** This node's mesh. **/
        Mesh *mesh;
        /** This node's local transformation. Will be a global transformation
         *  for its children.**/
        glm::mat4 transformation;
        /** This node's global transformation (to be applied before local
         *  transformation). **/
        glm::mat4 worldTransformation;
        /** This node's children. **/
        vector<SceneGraphNode*> children;
};

#endif /* SCENEGRAPHNODE_H_ */
