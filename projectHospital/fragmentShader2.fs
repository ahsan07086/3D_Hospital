#version 330 core

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoord;

out vec4 FragColor;

struct Material {
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
};

struct PointLight {
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float k_c;  // Constant attenuation
    float k_l;  // Linear attenuation
    float k_q;  // Quadratic attenuation
};

#define NR_POINT_LIGHTS 4

uniform Material material;
uniform PointLight pointLights[NR_POINT_LIGHTS];
uniform vec3 viewPos;

vec3 CalcPointLight(Material material, PointLight light, vec3 N, vec3 fragPos, vec3 V);

void main()
{
    vec3 N = normalize(Normal);
    vec3 V = normalize(viewPos - FragPos);
    
    vec3 result = vec3(0.0f);
    for (int i = 0; i < NR_POINT_LIGHTS; i++)
        result += CalcPointLight(material, pointLights[i], N, FragPos, V);
    
    vec4 texColor = texture(material.diffuse, TexCoord);
    FragColor = vec4(result, 1.0f) * texColor; // Combine lighting with texture color
}

vec3 CalcPointLight(Material material, PointLight light, vec3 N, vec3 fragPos, vec3 V)
{
    vec3 L = normalize(light.position - fragPos);
    vec3 R = reflect(-L, N);

    float d = length(light.position - fragPos);
    float attenuation = 1.0f / (light.k_c + light.k_l * d + light.k_q * (d * d));

    vec3 ambient = texture(material.diffuse, TexCoord).rgb * light.ambient;
    vec3 diffuse = texture(material.diffuse, TexCoord).rgb * max(dot(N, L), 0.0) * light.diffuse;
    vec3 specular = texture(material.specular, TexCoord).rgb * pow(max(dot(V, R), 0.0), material.shininess) * light.specular;
    
    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;
    
    return (ambient + diffuse + specular);
}
