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

SceneGraphNode::SceneGraphNode(Mesh *mash)
{
    this->mesh   = mesh;
    this->parent = NULL;
}

SceneGraphNode::~SceneGraphNode()
{
    for(unsigned int index = 0; index < children.size(); index++)
    {
        delete &children[index];
    }
}

void SceneGraphNode::setTransformation(glm::mat4 matrix)
{
    transformation = matrix;
}

glm::mat4 SceneGraphNode::getTransformation()
{
    return transformation;
}

glm::mat4 SceneGraphNode::getWorldTransformation()
{
    return worldTransformation;
}

Mesh *SceneGraphNode::getMesh()
{
    return mesh;
}

void SceneGraphNode::setMesh(Mesh *mesh)
{
    this->mesh = mesh;
}

void SceneGraphNode::insertChild(SceneGraphNode *node)
{
    children.push_back(node);
    node->parent = this;
}

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

void SceneGraphNode::draw()
{
    if(mesh != NULL)
    {
        mesh->draw();
    }
}
