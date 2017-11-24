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

#include "SceneGraphNode.h"

/***********************************************************************
 * SceneGraphNode: Constructor.
 *
 * mesh:      The mesh to be drawn.
***********************************************************************/
SceneGraphNode::SceneGraphNode()
{
    mesh   = NULL;
    parent = NULL;
    worldTransformation = glm::mat4();
    transformation = glm::mat4();
}

/***********************************************************************
 * SceneGraphNode: Constructor.
 *
 * mesh:      The mesh to be drawn.
***********************************************************************/
SceneGraphNode::SceneGraphNode(Mesh *theMesh)
{
    mesh   = theMesh;
    parent = NULL;
    worldTransformation = glm::mat4();
    transformation = glm::mat4();
}

/***********************************************************************
 * SceneGraphNode: Destructor.
***********************************************************************/
SceneGraphNode::~SceneGraphNode()
{
    for(unsigned int index = 0; index < children.size(); index++)
    {
        delete &children[index];
    }
}

/***********************************************************************
 * setTransformation: Sets this node's transformation matrix.
 *
 * matrix:    The transformation matrix to be applied.
 *
 * return:    void
***********************************************************************/
void SceneGraphNode::setTransformation(glm::mat4 matrix)
{
    transformation = matrix;
}

/***********************************************************************
 * getTransformation: Returns this node's transformation matrix.
 *
 * return:    mat4
***********************************************************************/
glm::mat4 SceneGraphNode::getTransformation()
{
    return transformation;
}

/***********************************************************************
 * getWorldTransformation: Returns this node's world transformation
 *            matrix.
 *
 * return:    mat4
***********************************************************************/
glm::mat4 SceneGraphNode::getWorldTransformation()
{
    return worldTransformation;
}

/***********************************************************************
 * getMesh:   Returns a pointer to this node's mesh.
 *
 * return:    Mesh pointer
***********************************************************************/
Mesh *SceneGraphNode::getMesh()
{
    return mesh;
}

/***********************************************************************
 * setMesh:   Sets this node's mesh.
 *
 * mesh:      The mesh to be drawn.
 *
 * return:    void
***********************************************************************/
void SceneGraphNode::setMesh(Mesh *mesh)
{
    this->mesh = mesh;
}

/***********************************************************************
 * addChild:  Adds a child node to this parent (if no parent, then
 *            parent will be NULL).
 *
 * node:      The child node.
 *
 * return:    void
***********************************************************************/
void SceneGraphNode::addChild(SceneGraphNode *node)
{
    children.push_back(node);
    node->parent = this;
}

/***********************************************************************
 * update:    Updates all nodes applying parent transformations to child
 *            nodes.
 *
 * return:    void
***********************************************************************/
void SceneGraphNode::update()
{
    if(parent != NULL)
    {
        worldTransformation = parent->worldTransformation * transformation;
    }
    else
    {
        worldTransformation = transformation;
    }

    for(unsigned int index = 0; index < children.size(); index++)
    {
        children[index]->update();
    }

    /** Want to apply transformation when inherited. **/
}

/***********************************************************************
 * draw:      Draws all meshs in the scene graph.
 *
 * return:    void
***********************************************************************/
void SceneGraphNode::draw()
{
    if(mesh != NULL)
    {
        mesh->draw();
    }

    for(unsigned int index = 0; index < children.size(); index++)
    {
        children[index]->draw();
    }
}
