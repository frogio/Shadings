# Shading
Flat, Gouraud, Phong Shading 구현

## 개발 환경
Windows 10, Visual Studio 2022, Assimp, OpenGL, C++

## 참조 사이트 및 서적
https://learnopengl.com/Model-Loading/Assimp, </br>
『게임 프로그래머를 위한 수학과 OpenGL 프로그래밍』, 강영민 저, p. 283 ~ p. 285</br>

### Flat Shading
면 단위로 법선벡터를 계산하여 이를 조명벡터와 내적 후</br>
면의 음영을 결정하는 방식</br>

### Gouraud Shading
정점 단위로 법선벡터를 계산하여 퐁 쉐이딩으로 정점 색을 결정한 후</br>
이 정점 색상을 기준으로 보간을 수행하여 프래그먼트의 색상을 결정짓는다.</br>
노말벡터를 보간하는것이 아니라 색상을 보간하는것이기 때문에 하이라이트 음영에서</br>
명암이 꺠지는 현상이 발생한다.</br>

정점의 노말벡터는 정점 자신의 이웃평면의 평균값을 취하고 노말라이즈하여 계산된다.</br>
이는 아래와 같이 계산된다.</br>

어떤 면을 구성하는 정점이 p0, p1, p2 라면 각각의 법선 벡터를 n0, n1, n2라 할 때</br>
모든 평면을 돌면서 정점 p0의 n0, p1의 n1, p2의 n2에 이웃평면의 노말벡터 N을 더한다</br>

모든 평면 F에 대해</br></br>
    n0 = n0 + N</br>
    n1 = n1 + N</br>
    n2 = n2 + N</br>

모든 정점의 노말벡터 n에 대해</br>
    n = normalize(n)</br>



### Blinn-Phong Shading
OpenGL 2.0 Shader 언어로 구현되었다.</br>

Gouraud Shading이 정점의 색상을 보간한 것이라면,</br>
Phong Shading은 정점의 노말벡터를 보간하여 픽셀당 노말벡터를 계산한 뒤,</br>
각 노말벡터에 대해 Phong Shading으로 계산하여 색상을 결정한 것으로 보면 된다.</br>

이떄 Phong Shading은 아래와 같이 계산된다.</br></br>
Phong = ambient + Idiff * diffuse + (Ispec)^shininess * specular</br>

ambient는 주변광</br>

Idiff은 난반사 광강도, 평면의 노말 벡터와 조명방향을 내적하여 계산된다.</br>
diffuse는 난반사 계수(물체의 재질) * 광원의 색상 및 세기 (Component-wise Multiplication)</br>

Isepc은 정반사 광강도, 조명 벡터와 시점벡터를 이등분하는 반벡터와 평면의 노말 벡터를 내적하여 결정된다.</br>
specular는 정반사 계수(물체의 재질) * 광원의 색상 및 세기(Component-wise Multiplication)</br>

반벡터란 조명벡터와 시점벡터를 이등분하는 벡터이다.</br>
원래 Phong Shading에선 반사벡터 R과 시점 벡터 E와의 내적을 통해서 정반사 광강도를 계산하지만</br>
Blinn 모델에선 반벡터라는 개념을 도입해 R과 E의 내적을 근사한다.</br>

반벡터가 평면의 노말벡터와 완전히 일치하는 경우 시점벡터와 반사벡터가 완전히 일치하게 되므로</br>
광강도는 최대가 된다. 이를 통해 광강도 계산을 더 간편히 근사할 수 있다.</br>

### 실행 결과

#### Flat Shading
<img width="1920" height="1031" alt="FlatShading" src="https://github.com/user-attachments/assets/7e1ab53c-0df9-40e9-833c-b15ff78dfe98" />

#### Gouraud Shading
<img width="1920" height="1031" alt="image" src="https://github.com/user-attachments/assets/df6d26df-8440-4d93-8293-edcecc781173" />

#### Blinn-Phong Shading
<img width="1920" height="1031" alt="쉐이딩비교 2" src="https://github.com/user-attachments/assets/13f285d2-6f85-4b02-944f-1e6d55d87474" />

