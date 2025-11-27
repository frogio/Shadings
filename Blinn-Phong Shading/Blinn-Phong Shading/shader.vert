varying vec4 diffuse, ambient;
varying vec3 normal, halfVector;

void main(){
	// 법선 벡터를 시점 공간으로 변환하고 정규화한다.
	// 법선 벡터가 여러 아핀변환 이후에도 표면에 직각인 특징을 유지하기 위해 gl_NormalMatrix를 곱해준다.
	normal = normalize(gl_NormalMatrix * gl_Normal);

	// 반 벡터를 프래그먼트 쉐이더로 보낸다.
	halfVector = gl_LightSource[0].halfVector.xyz;

	diffuse = gl_FrontMaterial.diffuse * gl_LightSource[0].diffuse;
	ambient = gl_FrontMaterial.ambient * gl_LightSource[0].ambient;
	ambient += gl_LightModel.ambient * gl_FrontMaterial.ambient;
	
	// 정점변환은 고정 파이프라인 그대로 적용
	gl_Position = ftransform();
}