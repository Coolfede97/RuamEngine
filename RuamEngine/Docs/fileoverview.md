# Project structure


./RuamEngine -> Entry Point


### Inside /RuamCore:


/Files/FileFunctions -> Read files


/Input/Input -> enums KeyCode y MousePosition, class Input


/Maths/Vec: \
    /Vec2, /Vec3, /Vec4 -> data structs


/Objects: \
    /Object -> class Object:\
        _public_:\
        `const ComponentVector& getComponents() const` \
        `template<class Comp> Comp* addComponent()`\
        `template<class Comp> Comp* getComponent()`\
        _private_:\
        `unsigned int m_id ` \
        `static unsigned int s_id_count` \
        `std::map<std::type_index, ComponentVector> m_components;`


/Component -> class Component (abstract):\
    _public_:\
    `Component(unsigned int obj_id)` (constructor) \
    `virtual void Start()` \
    `virtual void Update()` \
    _protected_:\
    `unsigned int m_object_id`




# Types


- ComponentVector = std::vector<std::shared_ptr<Component>>

