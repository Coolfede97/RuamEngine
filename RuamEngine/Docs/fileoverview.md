# Project structure

## /Root

- @/RuamEngine -> Entry Point


## ***/RuamCore***:


### /Files

- /FileFunctions -> Read files



### /Input

- /Input -> enums KeyCode y MousePosition, class Input



### /Maths

#### /Vec

- /Vec2, /Vec3, /Vec4 -> struct VecX in each

```cpp
    VecX(double coord1, double coord2...) //constructor

    VecX operator+, -, *, / (VecX) const
    VecX operator/ (float) const

    double Magnitude() const
    VecX Normalized() const
    VecX To(VecX target) const
    float DotProduct(VecX other) const
```



### /Objects

- /Object -> class Object:

```cpp
public:

    const ComponentVector& getComponents() const 

    template<class Comp> Comp* addComponent()  

    template<class Comp> Comp* getComponent()

private:

    unsigned int m_id //internal

    static unsigned int s_id_count //serial count

    std::map<std::type_index, ComponentVector> m_components
```



- /Component -> class Component (abstract):  

```cpp
public: 

    Component(unsigned int obj_id) //constructor  
    virtual void Start()
    virtual void Update() 

protected:  

    unsigned int m_object_id  
``` 
  
- /Scene -> class Scene:  

```cpp
public:  

Scene() //constructor  

private:  

    std::list<unsigned int> m_objects  
    unsigned int m_id
    static unsigned int s_id_count
```


### /Rendering

- /Camera -> class Camera:  

```cpp

``` 


---

# Types


- ComponentVector = std::vector<std::shared_ptr<Component>>

