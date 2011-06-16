#include <Ogre.h>

#include <cstdint>

int main() {
    Ogre::Root* ogre_root = new Ogre::Root();

    ogre_root->loadPlugin("/usr/lib/OGRE/RenderSystem_GL.so");
    Ogre::RenderSystem* ogre_render_system = ogre_root->getRenderSystemByName("OpenGL Rendering Subsystem");
    ogre_root->setRenderSystem(ogre_render_system);

    ogre_root->initialise(false, "Ogre Minimal Example");
    Ogre::RenderWindow* ogre_render_window = ogre_root->createRenderWindow("RenderWindow", 1024, 768, false);
    
    Ogre::SceneManager* ogre_scene_manager = ogre_root->createSceneManager("DefaultSceneManager");
    ogre_scene_manager->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));

    Ogre::Entity* sphere = ogre_scene_manager->createEntity(Ogre::SceneManager::PrefabType::PT_SPHERE);

    Ogre::SceneNode* root_node = ogre_scene_manager->getRootSceneNode()->createChildSceneNode();

    root_node->attachObject(sphere);

    Ogre::Camera* ogre_camera = ogre_scene_manager->createCamera("lolcam");
    ogre_camera->setPosition(Ogre::Vector3(0, 10, 500));
    ogre_camera->lookAt(Ogre::Vector3(0, 0, 0));

    Ogre::Viewport* ogre_viewport = ogre_render_window->addViewport(ogre_camera);
    ogre_viewport->setBackgroundColour(Ogre::ColourValue(1, 0.1, 0.3));

    Ogre::Light* light = ogre_scene_manager->createLight();
    light->setPosition(20, 80, 50);

    uint16_t frames_rendered = 0;
    while(frames_rendered < 100) {
        ogre_root->renderOneFrame();
        Ogre::WindowEventUtilities::messagePump();
    }

    delete ogre_root;

    return 0;
}
