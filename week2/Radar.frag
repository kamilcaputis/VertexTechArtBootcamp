#ifdef GL_ES
precision highp float;
#endif
#define PI 3.1415926538

uniform float u_time;
uniform vec2  u_resolution;

// Shadertoy-style entry point
void mainImage(out vec4 fragColor, in vec2 fragCoord)
{
    //normalized pixel coordinates (from 0 to 1)
    vec2 uv = fragCoord / u_resolution.xy;
    float ratio = u_resolution.x / u_resolution.y;
   
    //makes uv range from -1 to +1 0.5 becomes 0
    uv = uv * 2.0 - 1.0;
    
    //apply ratio to make square
    uv.x *= ratio;
    
    // angle in radians from uv position (direction)
    float angle = atan(uv.y,uv.x);
    
    float bladeCount = 1.0;
    float bladeRadius = 1.0;
    float sp = 1.0;
    float pulseSp = 2.0; //speed of blade pulse
    float minAlpha = 0.1; //so blade is not fully dark
    float maxAlpha = 0.9; //make sure min and max add up to 1.0!!! so no (0.2, 0.9)
    
    float bladeAngle = angle + (u_time * sp);
    
    // distance from center (used for both radial grid and spokes)
    float dist = length(uv);

    float gridRadii = dist - bladeRadius;
    float radialLineFq = 10.0; //how many concentric circles we want
    float radialGrid = fract(gridRadii * radialLineFq); //fract makes the angled "squares"
    
    //make lines thinner and anti-aliased
    float radialLine = smoothstep(0.1, 0.2, radialGrid) - smoothstep(0.2, 0.3, radialGrid);

    float angularLineFq = 12.0; //number of angular lines, think degree increments so 12 is 30degree incremets

    // ----- fixed angular lines: even thickness from center to edge -----
    // size of each "pizza slice" in radians
    float sector = 2.0 * PI / angularLineFq;

    // put angle into range [-sector/2, +sector/2] for the current spoke
    float localAngle = mod(angle + sector * 0.5, sector) - sector * 0.5;

    // distance from pixel to the center line of the spoke in world space
    // line passes through origin, so distance ≈ dist * abs(sin(localAngle))
    float lineDistance = dist * abs(sin(localAngle));

    // thickness of spoke in uv space (adjust for thicker/thinner spokes)
    float lineWidth = 0.01;

    // 1 on the spoke, 0 away from it, with smooth edge
    float angularLine = 1.0 - smoothstep(0.0, lineWidth, lineDistance);
    // ---------------------------------------------------------------

    // Combine the lines
    float grid = radialLine + angularLine;
    
    //pulse that makes blade fade in and out over time. normalize sin to 0 - 1 values 
    //multiply time by pulse speed
    float pulse = minAlpha + maxAlpha * (0.5 + 0.5 * sin(u_time * pulseSp));
    
    //float blades = smoothstep(0.9, 1.0, sin(bladeAngle * bladeCount)) * pulse;
    float s = sin(bladeAngle);

    // one sharp leading edge (unused now)
    float head = smoothstep(0.95, 1.0, s);

    // trailing fade behind it (unused now)
    float tail = max(s, 0.0);
    // tail = pow(tail, 0.0);  // REMOVE: this just gives 1 and can cause 0^0 issues

    float sweepAngle = -u_time * sp;//where the beam is pointing

    // relative angle pixel vs sweep
    float rel = angle - sweepAngle;
    // wrap to [-PI, PI] so it’s continuous
    rel = atan(sin(rel), cos(rel));

    // tail length in radians
    float tailLen = 3.2;               
    
    // map rel ∈ [-tailLen, 0] -> t ∈ [0,1]
    float t = clamp(-rel / tailLen, 0.0, 1.0);

    // shape: t^p, lower p = softer/longer tail, higher p = sharper head
    float blades = pow(t, 4.0);         // try 2.0 for softer, 4.0 for sharper
    // optionally multiply by your pulse:
    //blades *= pulse;
    
    float circle = 1.0 - step((bladeRadius + 1.0),length(uv));
    
    grid *= circle; //make grid only as big as the circle
    
    vec3 gridRgb = grid * vec3(0.02, 0.2, 0.03);
    vec3 anim = vec3(blades * circle) * vec3(0.8,1.0,0.2);
    vec3 radar = gridRgb + anim;
    
    // Output to screen
    fragColor = vec4(radar,1.0);
}

// Actual GLSL entry point for WebGL / GLSL Canvas
void main() {
    vec4 color;
    mainImage(color, gl_FragCoord.xy);
    gl_FragColor = color;
}
