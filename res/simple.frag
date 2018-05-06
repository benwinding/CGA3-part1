#version 330

// in vec2 TexCoords;
// in vec3 Normal;
// in vec3 FragPos;
in vec3 pos;

// struct Material {
//     sampler2D diffuse;
//     sampler2D specular;    
//     float shininess;
//     vec3 colour;
// }; 

// struct Light {
//     int isDirectional;  

//     vec3 position;  
//     vec3 direction;
//     float cutOff;
//     float outerCutOff;
  
//     vec3 ambient;
//     vec3 diffuse;
//     vec3 specular;
    
//     float constant;
//     float linear;
//     float quadratic;
// };

// #define MAX_LIGHTS 10

// uniform int numLights;
// uniform vec3 viewPos;
// uniform Material material;
// uniform Light allLights[MAX_LIGHTS];

out vec4 FragColor;
out vec3 FragPos;

// vec3 ApplySpotLight(Light light, Material material)
// {
//     vec3 lightDir = normalize(light.position - FragPos);
          
//     // ambient
//     vec3 ambient = material.colour * light.ambient * texture(material.diffuse, TexCoords).rgb;
    
//     // diffuse 
//     vec3 norm = normalize(Normal);
//     float diff = max(dot(norm, lightDir), 0.0);
//     vec3 diffuse = light.diffuse * diff * texture(material.diffuse, TexCoords).rgb;  
    
//     // specular
//     vec3 viewDir = normalize(viewPos - FragPos);
//     vec3 reflectDir = reflect(-lightDir, norm);  
//     float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
//     vec3 specular = light.specular * spec * texture(material.specular, TexCoords).rgb;
    
//     // check if lighting is inside the spotlight cone
//     float theta     = dot(lightDir, normalize(-light.direction));
//     float epsilon   = light.cutOff - light.outerCutOff;
//     float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);
//     diffuse  *= intensity;
//     specular *= intensity;
    
//     // attenuation
//     float distance    = length(light.position - FragPos);
//     float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    
    
//     diffuse  *= attenuation;
//     specular *= attenuation;   
//     ambient  *= attenuation;

//     vec3 result = ambient + diffuse + specular;
//     return result;
// }

// vec3 ApplyPointLight(Light light, Material material)
// {
//     vec3 lightDir = normalize(light.position - FragPos);
          
//     // ambient
//     vec3 ambient = material.colour * light.ambient * texture(material.diffuse, TexCoords).rgb;
    
//     // diffuse 
//     vec3 norm = normalize(Normal);
//     vec3 diffuse = light.diffuse * norm * texture(material.diffuse, TexCoords).rgb;  
   
//     // attenuation
//     float distance    = length(light.position - FragPos);
//     float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    
    
//     diffuse  *= attenuation;
//     ambient  *= attenuation;

//     vec3 result = ambient + diffuse;
//     return result;
// }

void main(void)
{
    vec3 linearColor = vec3(0);
    // for(int i = 0; i < numLights; ++i){
    //     Light light = allLights[i];
    //     if(light.isDirectional == 1)
    //         linearColor += ApplySpotLight(light, material);
    //     else
    //         linearColor += ApplyPointLight(light, material);
    // }

    // Light light;

    // light.position = vec3(1,3,0);

    // light.ambient = vec3(1,0,0);
    // light.diffuse = vec3(1,0,0);
    // light.specular = vec3(1,0,0);

    // linearColor += ApplyPointLight(light, material);

    // FragColor = vec4(linearColor, 1.0);
    FragColor = vec4(1,1,0, 1.0);
    FragPos = pos;
}
