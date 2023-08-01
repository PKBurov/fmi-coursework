<?xml version="1.0"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:fo="http://www.w3.org/1999/XSL/Format">
<xsl:output method="xml" version="1.0" indent="yes"/>
<xsl:template match="/">
	<fo:root>
	
		<fo:layout-master-set>
			<fo:simple-page-master page-height="297mm" page-width="210mm" margin="5mm 25mm 5mm 25mm" master-name="template">
				<fo:region-body margin="20mm 0mm 20mm 0mm"/>
			</fo:simple-page-master>
		</fo:layout-master-set>
<!--===========================Title===============================-->

		<fo:page-sequence master-reference="template">
			<fo:flow flow-name="xsl-region-body">
				<fo:block position ="absolute" text-align ="center" font-weight="bold" margin-bottom="50mm"
					font-family="Calibri" font-size="48pt" padding-before="50mm" color="black">
					Hotel Catalog
				</fo:block>
			</fo:flow>
		</fo:page-sequence>


		<fo:page-sequence master-reference="template">
			<fo:flow flow-name="xsl-region-body">
				<fo:block position ="absolute" text-align ="center" font-weight="bold" margin-bottom="50mm"
					font-family="Calibri" font-size="30pt" padding-before="50mm" color="black">
					Hotels
				</fo:block>
			</fo:flow>
		</fo:page-sequence>
		<!--===========================WebDesigns PRERABOTVANE===============================-->
        <xsl:for-each select="//hotel">
			<xsl:variable name="region_ref_id" select="@region_ref"/>
			<xsl:variable name="star_rating_ref" select="@star_rating_ref"/>
			
        	<fo:page-sequence master-reference="template">
			<fo:flow flow-name="xsl-region-body">
				<!--Заглавие на хотела-->
				<fo:block-container position="absolute" top="-2.5cm" left="-2.5cm">
					<fo:block position="absolute" text-align="center" padding-before="2cm" margin-left="2.5cm"
								font-family="Calibri" font-size="20pt" color="black">
						<xsl:value-of select="hotel/@name"/>
					</fo:block>
					<!--Снимка-->
					<fo:block position="absolute" text-align="center" padding-before="7mm" margin-left="2.5cm">
					   <fo:external-graphic src="{unparsed-entity-uri(logo/@src)}"></fo:external-graphic>
					</fo:block>
					<!--City-->
					<fo:block position="relative" font-family="Calibri" font-weight="bold" font-size="15pt" color="black" 
					padding-before="5mm" margin-left="2cm">
						City:
						<fo:inline position="relative" padding-left="32mm" font-weight="normal" font-size="14pt">
							<xsl:value-of select="hotel/@city"/> 
						</fo:inline>
					</fo:block> 
					<!--Region-->
					<fo:block position="relative" font-family="Calibri" font-weight="bold" font-size="15pt" color="black" 
					padding-before="5mm" margin-left="2cm">
						Region:
						<fo:inline position="relative" padding-left="10mm" font-weight="normal" font-size="14pt">
							<!-- Това ще работи ако е вътре в самия елемент не знам дали ще работи като е атрибут-->
							<xsl:value-of select="//region[@id = $region_ref_id ]/name"/> 
						</fo:inline>
					</fo:block>
					<!--Рейтинг на хотела-->
					<fo:block position="relative" font-family="Calibri" font-weight="bold" font-size="15pt" color="black" 
					padding-before="5mm" margin-left="2cm">
						Coach:
						<fo:inline position="relative" padding-left="27mm" font-weight="normal" font-size="14pt">
							<xsl:value-of select="//star_rating[@id = $star_rating_ref ]/name"/>
						</fo:inline>
					</fo:block>
					<!--Amenities-->
					<fo:block position="relative" font-family="Calibri" font-weight="bold" font-size="15pt" color="black" 
					padding-before="5mm" margin-left="2cm">
						General Amenities:
						<!--restaurant-->
						<fo:inline position="relative" padding-left="27mm" font-weight="normal" font-size="14pt">
							<xsl:value-of select="hotel/general_amenities/@restaurant"/>
						</fo:inline>
						<!--pool-->
						<fo:inline position="relative" padding-left="27mm" font-weight="normal" font-size="14pt">
							<xsl:value-of select="hotel/general_amenities/@pool"/>
						</fo:inline>
						<!--spa-->
						<fo:inline position="relative" padding-left="27mm" font-weight="normal" font-size="14pt">
							<xsl:value-of select="hotel/general_amenities/@spa"/>
						</fo:inline>
						<!--gym-->
						<fo:inline position="relative" padding-left="27mm" font-weight="normal" font-size="14pt">
							<xsl:value-of select="hotel/general_amenities/@gym"/>
						</fo:inline>
						<!--bar-->
						<fo:inline position="relative" padding-left="27mm" font-weight="normal" font-size="14pt">
							<xsl:value-of select="hotel/general_amenities/@bar"/>
						</fo:inline>
						<!--parking-->
						<fo:inline position="relative" padding-left="27mm" font-weight="normal" font-size="14pt">
							<xsl:value-of select="hotel/general_amenities/@parking"/>
						</fo:inline>
						<!--special-->
						<fo:inline position="relative" padding-left="27mm" font-weight="normal" font-size="14pt">
							<xsl:value-of select="hotel/general_amenities/specials/@special"/>
						</fo:inline>
					</fo:block>
				<!--Room Amenities-->
					<fo:block position="relative" font-family="Calibri" font-weight="bold" font-size="15pt" color="black"
					padding-before="5mm" margin-left="2cm">
						Room Amenities:
						<!--wifi-->
						<fo:inline position="relative" padding-left="27mm" font-weight="normal" font-size="14pt">
							<xsl:value-of select="hotel/room_amenities/@wifi"/>
						</fo:inline>
						<!--tv-->
						<fo:inline position="relative" padding-left="27mm" font-weight="normal" font-size="14pt">
							<xsl:value-of select="hotel/general_amenities/@tv"/>
						</fo:inline>
						<!--minibar-->
						<fo:inline position="relative" padding-left="27mm" font-weight="normal" font-size="14pt">
							<xsl:value-of select="hotel/general_amenities/@minibar"/>
						</fo:inline>
						<!--air_conditioning-->
						<fo:inline position="relative" padding-left="27mm" font-weight="normal" font-size="14pt">
							<xsl:value-of select="hotel/general_amenities/@ari_conditioning"/>
						</fo:inline>
						<!--specials-->
						<fo:inline position="relative" padding-left="27mm" font-weight="normal" font-size="14pt">
							<xsl:value-of select="hotel/general_amenities/specials/@special"/>
						</fo:inline>
					</fo:block>
					
					
					<fo:block position="relative" font-family="Calibri" font-weight="bold" font-size="15pt" color="black" 
					padding-before="5mm" margin-left="2cm">
						Description:
						<fo:inline position="relative" padding-left="31mm" font-weight="normal" font-size="14pt">
							<xsl:value-of select="description"/> 
						</fo:inline>
					</fo:block> 
				</fo:block-container>
			</fo:flow>
		</fo:page-sequence>
		</xsl:for-each>
		
		<fo:page-sequence master-reference="template">
			<fo:flow flow-name="xsl-region-body">
				<fo:block position ="absolute" text-align ="center" font-weight="bold" margin-bottom="50mm"
					font-family="Calibri" font-size="30pt" padding-before="50mm" color="black">
					Football team coaches
				</fo:block>
			</fo:flow>
		</fo:page-sequence>


	</fo:root>

</xsl:template>

</xsl:stylesheet>