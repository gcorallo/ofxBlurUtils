#version 150

uniform sampler2DRect tex0;

uniform float blurAmntR;
uniform float blurAmntG;
uniform float blurAmntB;

uniform float gain;

uniform bool atenuateLastPass;

in vec2 texCoordVarying;
out vec4 outputColor;

void main()
{

    vec4 color;
	
    color += 2.0 * texture(tex0, texCoordVarying );
    
    color.r += 1.0 * texture(tex0, texCoordVarying + vec2(0.0, blurAmntR * 1.0)).r;
    color.r += 1.0 * texture(tex0, texCoordVarying + vec2(0.0, blurAmntR * -1.0)).r;

    color.g += 1.0 * texture(tex0, texCoordVarying + vec2(0.0, blurAmntG * 1.0)).g;
    color.g += 1.0 * texture(tex0, texCoordVarying + vec2(0.0, blurAmntG * -1.0)).g;
    
    color.b += 1.0 * texture(tex0, texCoordVarying + vec2(0.0, blurAmntB * 1.0)).b;
    color.b += 1.0 * texture(tex0, texCoordVarying + vec2(0.0, blurAmntB * -1.0)).b;

    
    
    color /= 4.0;
    
    color.rgb *=gain;
    
    if(atenuateLastPass){
        color.rgb *=.99;
    }
    
    color.a = 1.0;
    
    outputColor = color;
}
