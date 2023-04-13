<?xml version="1.0"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:fo="http://www.w3.org/1999/XSL/Format">
<xsl:output method="xml" version="1.0" indent="yes"/>
<xsl:template match="/">
	<fo:root>
		<fo:layout-master-set>
			<fo:simple-page-master page-height="297mm" page-width="210mm"
				margin="5mm 25mm 5mm 25mm" master-name="page">
				<fo:region-body margin="20mm 0mm 20mm 0mm"/>
			</fo:simple-page-master>
		</fo:layout-master-set>

<!--===========================HeaderPage===============================-->
		
		<fo:page-sequence master-reference="page">
			<fo:flow flow-name="xsl-region-body">
				<fo:block-container position ="absolute" top="-2.5cm" left = "-2.5cm" >
					<fo:block position ="absolute" text-align ="center" font-weight="bold" margin-left="2cm"
					font-family="Monotype Corsiva" font-size="48pt" padding-before="50mm" color="black" >
						<fo:block margin-bottom="30mm">
							Каталог на пещери в България
						</fo:block>
						<fo:external-graphic src="url('images/header_page.jpg')" text-align ="center" padding-after="10mm" margin-bottom="30mm" content-height="400" content-width="580" ></fo:external-graphic>
					</fo:block>
				</fo:block-container>
			</fo:flow>
		</fo:page-sequence>
		
<!--===============================Caves=================================-->
			
		<fo:page-sequence master-reference="page">
			<fo:flow flow-name="xsl-region-body">
				<fo:block-container position ="relative" top="-2.5cm" left = "-2.5cm" >											
						
										
					<fo:block position="relative" text-align ="center" font-family="Arial" font-weight="bold" font-size="22pt" color="black" padding-before="5mm">
						Пещери в Южноцентрален район
					</fo:block> 

					<fo:block position="relative" padding-before = "5mm" >			
						<xsl:for-each select=".//location[@regionId='SC']/cave">												
							<xsl:apply-templates select="."/>		
						</xsl:for-each>
					</fo:block>


					<fo:block position="relative" text-align ="center" font-family="Arial" font-weight="bold" font-size="22pt" color="black" padding-before="5mm">
						Пещери в Северозападен район
					</fo:block> 

					<fo:block position="relative" padding-before = "5mm" >			
						<xsl:for-each select=".//location[@regionId='NW']/cave">												
							<xsl:apply-templates select="."/>		
						</xsl:for-each>
					</fo:block>

					
					<fo:block position="relative" text-align ="center" font-family="Arial" font-weight="bold" font-size="22pt" color="black" padding-before="5mm">
						Пещери в Северoизточен район
					</fo:block> 

					<fo:block position="relative" padding-before = "5mm" >			
						<xsl:for-each select=".//location[@regionId='NC']/cave">												
							<xsl:apply-templates select="."/>		
						</xsl:for-each>
					</fo:block>								
								
							
				</fo:block-container>
			</fo:flow>
		</fo:page-sequence>
		
	</fo:root>
</xsl:template> 


<!--===============================CaveTemplate=================================-->

	<xsl:template match="cave">

		<fo:block position="relative" text-align ="center" font-family="Arial" font-style="italic" font-weight="bold" color="black" font-size="19pt"
		padding-before="5mm">
				<xsl:value-of select="./title/text()"/> 
		</fo:block> 
		
		<fo:block position="absolute" text-align = "center" padding-before = "10mm" padding-after="5mm" >
			<xsl:apply-templates select="./image"/>
		</fo:block>	
		
		<fo:block position="relative" font-family="Arial" font-weight="bold" font-size="14pt" color="black" padding-before="5mm">
			Населено място: 
			<fo:inline position="relative" padding-left="5mm" font-weight="normal" font-size="14pt" >
				<xsl:value-of select="./populatedPlace/text()"/> 
			</fo:inline>
						
		</fo:block> 
				
		<fo:block position="relative" font-weight="bold" font-family="Arial" color="black" font-size="14pt"
		padding-before="5mm" padding-after="5mm">
			Характеристика:			
			<fo:block position="relative" padding-before="5mm" padding-left="5mm" font-weight="normal" font-size="14pt" >
				<xsl:apply-templates select="./characteristics"/> 
			</fo:block>
		</fo:block> 
		
		<fo:block position="relative" font-family="Arial" font-weight="bold" font-size="14pt" color="black" 
		padding-before="5mm">
			Описание:
			<fo:inline position="relative" padding-left="5mm" font-weight="normal" font-size="14pt" >
				<xsl:value-of select="./description/text()"/> 
			</fo:inline>
		</fo:block> 
		
		<fo:block position="relative" font-weight="bold" font-family="Arial" color="black" font-size="14pt"
		padding-before="5mm" padding-after="5mm">
			Допълнителна информация:			
			<fo:block position="relative" padding-before="5mm" padding-left="5mm" font-weight="normal" font-size="13pt" >
				<xsl:apply-templates select="./additionalInfo"/> 
			</fo:block>
		</fo:block>

		<fo:block position="relative" font-weight="bold" font-family="Arial" color="black" font-size="15pt"
		padding-before="5mm" padding-after="5mm">
			Близки забележителности:	
			<fo:block position="relative" padding-before = "5mm" page-break-after="always" font-size="14pt">			
				<xsl:for-each select="./nearLandmarks/landmark">												
					<xsl:apply-templates select="."/>		
				</xsl:for-each>
			</fo:block> 
		</fo:block>
							
	</xsl:template>

<!--============================CharacteristicsTemplate===============================-->

	<xsl:template match="characteristics">
	  <fo:table >
		<fo:table-body>		
			<fo:table-row>
				<fo:table-cell border="solid" font-weight="bold" text-align="center" padding-left="3mm" padding-right="3mm" padding-before="5mm" padding-after="5mm">
					<fo:block>Дължина</fo:block>
				</fo:table-cell>
				<fo:table-cell border="solid" text-align="center" padding-left="3mm" padding-right="3mm" padding-before="5mm" padding-after="5mm" font-size="12pt">
					<fo:block   >
						<xsl:value-of select="./length/text()"/>
					</fo:block >
				</fo:table-cell>
			</fo:table-row>			
			<fo:table-row>
				<fo:table-cell border="solid" font-weight="bold" text-align="center" padding-left="3mm" padding-right="3mm" padding-before="5mm" padding-after="5mm">
					<fo:block>Дълбочина</fo:block>
				</fo:table-cell>
				<fo:table-cell border="solid" text-align="center" padding-left="3mm" padding-right="3mm" padding-before="5mm" padding-after="5mm" font-size="12pt">
					<fo:block   >
						<xsl:value-of select="./depth/text()"/>
					</fo:block >
				</fo:table-cell>
			</fo:table-row>						
			<fo:table-row>
				<fo:table-cell border="solid" font-weight="bold" text-align="center" padding-left="3mm" padding-right="3mm" padding-before="5mm" padding-after="5mm">
					<fo:block>Надморска височина</fo:block>
				</fo:table-cell>
				<fo:table-cell border="solid" text-align="center" padding-left="3mm" padding-right="3mm" padding-before="5mm" padding-after="5mm" font-size="12pt">
					<fo:block   >
						<xsl:value-of select="./altitude/text()"/>
					</fo:block >
				</fo:table-cell>
			</fo:table-row>
			
			<fo:table-row>
				<fo:table-cell border="solid" font-weight="bold" text-align="center" padding-left="3mm" padding-right="3mm" padding-before="5mm" padding-after="5mm">
					<fo:block>Година</fo:block>
				</fo:table-cell>
				<fo:table-cell border="solid" text-align="center" padding-left="3mm" padding-right="3mm" padding-before="5mm" padding-after="5mm" font-size="12pt">
					<fo:block   >
						<xsl:value-of select="./year/text()"/>
					</fo:block >
				</fo:table-cell>
			</fo:table-row>
						
			<xsl:if test="./alias">
			<fo:table-row>
				<fo:table-cell border="solid" font-weight="bold" text-align="center" padding-left="3mm" padding-right="3mm" padding-before="5mm" padding-after="5mm">
					<fo:block>Псевдоним</fo:block>
				</fo:table-cell>
				<fo:table-cell border="solid" text-align="center" padding-left="3mm" padding-right="3mm" padding-before="5mm" padding-after="5mm" font-size="12pt">
					<fo:block   >
						<xsl:value-of select="./alias/text()"/>
					</fo:block >
				</fo:table-cell>
			</fo:table-row>
			</xsl:if>
			
			<xsl:if test="./temperature">
			<fo:table-row>
				<fo:table-cell border="solid" font-weight="bold" text-align="center" padding-left="3mm" padding-right="3mm" padding-before="5mm" padding-after="5mm">
					<fo:block>Температура</fo:block>
				</fo:table-cell>
				<fo:table-cell border="solid" text-align="center" padding-left="3mm" padding-right="3mm" padding-before="5mm" padding-after="5mm" font-size="12pt">
					<fo:block   >
						<xsl:value-of select="./temperature/text()"/>
					</fo:block >
				</fo:table-cell>
			</fo:table-row>
			</xsl:if>
			
		</fo:table-body>
	  </fo:table>
	</xsl:template>

<!--============================AdditionalInfoTemplate===============================-->

	<xsl:template match="additionalInfo">
	  <fo:table >
		<fo:table-header>
			<fo:table-row>
				<fo:table-cell border="solid" font-weight="bold" text-align="center">
					<fo:block>Телефон/Email</fo:block>
				</fo:table-cell>
				<fo:table-cell border="solid" font-weight="bold" text-align="center">
					<fo:block>Цена</fo:block>
				</fo:table-cell>
				<fo:table-cell border="solid" font-weight="bold" text-align="center">
					<fo:block>Работно време</fo:block>
				</fo:table-cell>
			</fo:table-row>
		</fo:table-header>
		<fo:table-body>
			<fo:table-row>
				<fo:table-cell text-align="center" border="solid" padding-before="5mm" padding-after="5mm" font-size="12pt">
					<fo:block>				
						<xsl:choose>
							<xsl:when test="./phoneNumber">
								<xsl:value-of select="./phoneNumber/text()"/>
							</xsl:when>
							<xsl:otherwise>
								<xsl:value-of select="./email/text()"/>
							</xsl:otherwise>
						</xsl:choose>					
					</fo:block>
				</fo:table-cell>
				<fo:table-cell border="solid" text-align="justify" padding-left="3mm" padding-right="3mm" padding-before="5mm" padding-after="5mm" font-size="12pt">
					<fo:block   >
						<xsl:value-of select="./cost/text()"/>
					</fo:block >
				</fo:table-cell>
				<fo:table-cell border="solid" text-align="justify" padding-left="3mm" padding-right="3mm" padding-before="5mm" padding-after="5mm" font-size="12pt">
					<fo:block>
						<xsl:value-of select="./workingHours/text()"/>
					</fo:block>
				</fo:table-cell>
			</fo:table-row>
		</fo:table-body>
	  </fo:table>
	</xsl:template>

<!--===============================ImageTemplate===========================-->

	<xsl:template match="image">
		<fo:external-graphic src="{unparsed-entity-uri(@href)}" content-height="410" content-width="510"/>
	</xsl:template>

<!--===============================NearLandmarkTemplate=================================-->

	<xsl:template match="landmark">
		<fo:block position="relative" font-weight="bold" font-family="Arial" color="black" padding-before="5mm" font-size="13pt"> 
			Име на забележителността: 
			<fo:inline position="relative" font-weight="normal" padding-left="5mm" font-size="13pt">
				<xsl:value-of select="./title/text()"/> 
			</fo:inline>
		</fo:block> 		
 
				
		<fo:block position="absolute" text-align = "center" padding-before = "10mm" >
			<xsl:apply-templates select="./image"/>
		</fo:block>	
		
		<fo:block position="relative" font-weight="bold" font-family="Arial" color="black" padding-before="5mm" font-size="13pt" >
			Разстояние: 
			<fo:inline position="relative" font-weight="normal" padding-left="5mm" font-size="13pt">
				<xsl:value-of select="./distance/text()"/> 
			</fo:inline>
		</fo:block>
		
		<fo:block position="relative" font-family="Arial" font-weight="bold" font-size="13pt" color="black" 
		padding-before="5mm">
			Описание:
			<fo:inline position="relative" font-weight="normal" padding-left="5mm" font-size="13pt" >
				<xsl:value-of select="./description/text()"/> 
			</fo:inline>
		</fo:block> 
		
		<fo:block position="relative" font-weight="bold" font-family="Arial" color="black" font-size="13pt"
		padding-before="5mm" padding-after="5mm" page-break-after="always">
			Допълнителна информация:			
			<fo:block position="relative" padding-before="5mm" padding-left="5mm" font-weight="normal" font-size="13pt" >
				<xsl:apply-templates select="./additionalInfo"/> 
			</fo:block>
		</fo:block>
				
	</xsl:template>

</xsl:stylesheet>